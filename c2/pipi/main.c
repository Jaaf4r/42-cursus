#include "pipi.h"

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

void	valid_files(int *infile_fd, int *outfile_fd, char **av)
{
	*infile_fd = open(av[1], O_RDONLY);
	if (*infile_fd == -1)
		perror(av[1]);
	*outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile_fd == -1)
	{
		perror(av[4]);
		close(*infile_fd);
		exit(1);
	}
}

int	valid_path(char **av, char **env, int i, char **cmd)
{
	char	**cmd_args;
	char	*cmd_path;
	char	*tmp;
	char	**env_path;

	if (!env)
		return (0);
	cmd_args = ft_split(av[i], ' ');
	if (!cmd_args)
		return (0);
	tmp = getenv("PATH");
	if (!tmp)
		return (free_all(cmd_args), 0);
	env_path = ft_split(tmp, ':');
	if (!env_path)
		return (free_all(cmd_args), 0);
	tmp = NULL;
	while (*env_path)
	{
		tmp = ft_strjoin(*env_path, "/");
		if (!tmp)
			return (free_all(cmd_args), free_all(env_path), 0);
		cmd_path = ft_strjoin(tmp, cmd_args[0]);
		if (!cmd_path)
			return (free_all(cmd_args), free_all(env_path), free(tmp), 0);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
		{
			*cmd = ft_strdup(cmd_path);
			free(cmd_path);
			return (free_all(cmd_args), free_all(env_path), 1);
		}
		free(cmd_path);
		env_path++;
	}
	return (perror("Command not found\n"), 0);
}

// char	*command_execution(char **av, char **env, int i)
// {
// 	char	**cmd_args;
// 	char	*cmd_path;
// 	char	*tmp;
// 	char	**env_path;

// 	if (!env)
// 		return (NULL);
// 	if (access(av[i], X_OK) == 0)
// 		return (av[i]);
// 	cmd_args = ft_split(av[i], ' ');
// 	if (!cmd_args)
// 		return (NULL);
// 	tmp = getenv("PATH");
// 	if (!tmp)
// 		return (free_all(cmd_args), NULL);
// 	env_path = ft_split(tmp, ':');
// 	if (!env_path)
// 		return (free_all(cmd_args), NULL);
// 	tmp = NULL;
// 	while (*env_path)
// 	{
// 		tmp = ft_strjoin(*env_path, "/");
// 		if (!tmp)
// 			return (free_all(cmd_args), free_all(env_path), NULL);
// 		cmd_path = ft_strjoin(tmp, cmd_args[0]);
// 		if (!cmd_path)
// 			return (free_all(cmd_args), free_all(env_path), free(tmp), NULL);
// 		free(tmp);
// 		if (access(cmd_path, X_OK) == 0)
// 			return (free_all(cmd_args), free_all(env_path), free(cmd_path), cmd_path);
// 		free(cmd_path);
// 		env_path++;
// 	}
// 	return (perror("Command not found\n"), NULL);
// }

int	main(int ac, char **av, char **env)
{
	int		infile_fd;
	int		outfile_fd;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd[2] = {NULL, NULL};
	char	**cmd_args;

	if (ac != 5 || !valid_path(av, env, 2, &cmd[0]) || !valid_path(av, env, 3, &cmd[1]))
		return (1);
	valid_files(&infile_fd, &outfile_fd, av);
	if (pipe(pipefd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Error with fork\n"), 1);
	if (pid1 == 0)
	{
		if (infile_fd != -1)
		{
			dup2(infile_fd, STDIN_FILENO);
			close(infile_fd);
		}
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		close(outfile_fd);
		close(pipefd[0]);
		cmd_args = ft_split(av[2], ' ');
		if (!cmd_args)
			return (1);
		execve(cmd[0], av, env);
		perror(av[2]);
		free_all(cmd_args);
		exit(127);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Error with fork\n"), 1);
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(pipefd[0]);
		close(outfile_fd);
		close(infile_fd);
		close(pipefd[1]);
		cmd_args = ft_split(av[3], ' ');
		if (!cmd_args)
			return (1);
		execve(cmd[1], av, env);
		perror(av[3]);
		free_all(cmd_args);
		exit(127);
	}
	close(pipefd[0]);
	close(outfile_fd);
	close(infile_fd);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
