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

static int execute_command(char *cmd, char **env, int in_fd, int out_fd)
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

static void	handle_pipes(int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	int		in_fd;
	int		i;
	int		status;

	in_fd = open(av[1], O_RDONLY);
	if (in_fd == -1)
		perror(av[1]);

	i = 2;
	while (i < ac - 2)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
		{
			close(pipefd[0]);
			execute_command(av[i], env, in_fd, pipefd[1]);
		}
		close(pipefd[1]);
		if (in_fd != -1)
			close(in_fd);
		in_fd = pipefd[0];
		i++;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		int	out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd == -1)
		{
			perror(av[ac - 1]);
			exit(1);
		}
		execute_command(av[ac - 2], env, in_fd, out_fd);
	}
	if (in_fd != -1)
		close(in_fd);
	while (wait(&status) > 0)
		;
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (ft_putstr_fd("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2), 1);
	handle_pipes(ac, av, env);
	return (0);
}
