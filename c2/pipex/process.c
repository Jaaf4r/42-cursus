#include "pipex.h"

int	execute_command(char **cmd_args, char **env)
{
	char	*cmd_path;

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
    perror("execve");
    free_all(cmd_args);
    free(cmd_path);
    exit(127);
}

int	handle_first_child(int *file_fd, int *pipefd, char **av, char **env)
{
	char	**cmd_args;

	if (file_fd[0] == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		close(file_fd[1]);
		exit(1);
	}
	dup2(file_fd[0], STDIN_FILENO);
	close(file_fd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(file_fd[1]);
	close(pipefd[0]);
	cmd_args = ft_split(av[2], ' ');
	if (!cmd_args)
		exit(1);
	return (execute_command(cmd_args, env));
}

int	handle_second_child(int *pipefd, int *file_fd, char **av, char **env)
{
	char	**cmd_args;

	dup2(pipefd[0], STDIN_FILENO);
	dup2(file_fd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(file_fd[1]);
	close(file_fd[0]);
	close(pipefd[1]);
	cmd_args = ft_split(av[3], ' ');
	if (!cmd_args)
		exit(1);
	return (execute_command(cmd_args, env));
}
