#include "pipex.h"

static int	valid_arg_commands(char **av, int i)
{
	int		k;
	char	**cmd_args;
	char	*path_env;
	char	**env;
	char	*full_path;
	char	*cmd_path;

	cmd_args = ft_split(av[i], ' ');
	if (!cmd_args)
		return (printf("Error: Failed to split command\n"), 0);
	path_env = getenv("PATH");
	if (!path_env)
		return (printf("Error: PATH not set\n"), 0);
	env = ft_split(path_env, ':');
	if (!env)
		return (free_all(cmd_args), 0);
	k = 0;
	while (env[k])
	{
		full_path = ft_strjoin(env[k], "/");
		cmd_path = ft_strjoin(full_path, cmd_args[0]);
		free(full_path);
		if (access(cmd_path, X_OK) == 0)
			return (free(cmd_path), free_all(cmd_args), free_all(env), 1);
		free(cmd_path);
		k++;
	}
	free_all(env);
	printf("Command not found: %s\n", cmd_args[0]);
	free_all(cmd_args);
	return (0);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*full_path;
	char	*path_env;
	char	**paths;
	char	*cmd_path;

	if (!cmd || !env)
		return (NULL);

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(cmd_path, X_OK) == 0)
			return (free_all(paths),cmd_path);
		i++;
	}
	return (free_all(paths), NULL);
}

void	execute_command(char *cmd, char **env)
{
	char	**cmd_args = ft_split(cmd, ' ');
	char	*cmd_path = get_path(cmd_args[0], env);

	if (!cmd_path)
	{
		free_all(cmd_args);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	perror("execve failed\n");
	free_all(cmd_args);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	int		infile_fd;
	int		outfile_fd;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		return (1);

	if (!valid_arg_commands(av, 2) || !valid_arg_commands(av, 3))
		return (1);

	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd == -1)
	{
		perror(av[1]);
		return (1);
	}
	outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		perror(av[4]);
		close (infile_fd);
		return (1);
	}

	if (pipe(pipefd) == -1) {
		perror("Error opening the pipe\n");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1) {
		perror("Error with fork\n");
		return (1);
	}
	if (pid1 == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		
		close(pipefd[0]);
		close(infile_fd);
		close(outfile_fd);
		close(pipefd[1]);

		execute_command(av[2], env);
	}

	pid2 = fork();
	if (pid2 == -1) {
		perror("Error with fork\n");
		return (1);
	}
	if (pid2 == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);

		close(pipefd[0]);
		close(outfile_fd);
		close(infile_fd);
		close(pipefd[1]);

		execute_command(av[3], env);
	}


	close(infile_fd);
	close(outfile_fd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
