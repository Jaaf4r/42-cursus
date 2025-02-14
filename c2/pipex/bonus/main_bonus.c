#include "pipex_bonus.h"

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

static int	execute_command(char *cmd, char **env, int in_fd, int out_fd)
{
	char	**cmd_args;
	char	*cmd_path;

	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		exit(1);
	cmd_path = find_command(cmd_args[0]);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		free_all(cmd_args);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	free_all(cmd_args);
	free(cmd_path);
	exit(127);
}

static void	all_pipes_exc_last(int ac, char **av, char **env, t_fd *tools)
{
	while (tools->i < ac - 2)
	{
		if (pipe(tools->pipefd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		tools->pid = fork();
		if (tools->pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (tools->pid == 0)
		{
			close(tools->pipefd[0]);
			execute_command(av[tools->i], env, tools->infile_fd, tools->pipefd[1]);
		}
		close(tools->pipefd[1]);
		if (tools->infile_fd != -1)
			close(tools->infile_fd);
		tools->infile_fd = tools->pipefd[0];
		tools->i++;
	}
}

static void	handle_pipes(int ac, char **av, char **env, t_fd *tools)
{
	int	out_fd;

	if (!tools)
		return ;
	if (tools->heredoc_flag == 0)
	{
		tools->infile_fd = open(av[1], O_RDONLY);
		if (tools->infile_fd == -1)
			perror(av[1]);
	}
	all_pipes_exc_last(ac, av, env, tools);
	tools->pid = fork();
	if (tools->pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (tools->pid == 0)
	{
		out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd == -1)
		{
			perror(av[ac - 1]);
			exit(1);
		}
		execute_command(av[ac - 2], env, tools->infile_fd, out_fd);
	}
	if (tools->infile_fd != -1)
		close(tools->infile_fd);
	while (wait(&tools->status) > 0)
		;
}

static int	handle_heredoc(char *limiter, t_fd *tools)
{
	char	*line;

	if (pipe(tools->pipefd) == -1)
		return (-1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break;
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0 &&
			(line[ft_strlen(limiter)] == '\n'))
		{
			free(line);
			break;
		}
		ft_putstr_fd(line, tools->pipefd[1]);
		free(line);
	}
	close(tools->pipefd[1]);
	return (tools->pipefd[0]);
}

int	main(int ac, char **av, char **env)
{
	t_fd	tools;

	tools.i = 0;
	tools.infile_fd = -1;
	tools.status = 0;
	if (ac < 5)
		return (ft_putstr_fd("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2), 1);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		if (ac < 6)
			return (ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 file", 2), 1);
		tools.infile_fd = handle_heredoc(av[2], &tools);
		if (tools.infile_fd == -1)
			return (1);
		tools.outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (tools.outfile_fd == -1)
		{
			perror(av[ac - 1]);
			return (1);
		}
		tools.i = 3;
		tools.heredoc_flag = 1;
		handle_pipes(ac, av, env, &tools);
	}
	else
	{
		tools.i = 2;
		tools.heredoc_flag = 0;
		handle_pipes(ac, av, env, &tools);
	}
	return (0);
}
