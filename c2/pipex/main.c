#include "pipex.h"

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

int	init_processes(int *file_fd, char **av, char **env)
{
	pid_t	pid[2];
	int		pipefd[2];
	int		status;

	if (pipe(pipefd) == -1)
		return (perror("Pipe error"), 1);
	pid[0] = fork();
	if (pid[0] == -1)
		return (perror("Fork error"), 1);
	if (pid[0] == 0)
		handle_first_child(file_fd, pipefd, av, env);
	close(pipefd[1]);
	pid[1] = fork();
	if (pid[1] == -1)
		return (perror("Fork error"), 1);
	if (pid[1] == 0)
		handle_second_child(pipefd, file_fd, av, env);
	close(pipefd[0]);
	close(file_fd[0]);
	close(file_fd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int	file_fd[2];

	if (ac != 5)
		return (1);
	valid_files(&file_fd[0], &file_fd[1], av);
	return (init_processes(file_fd, av, env));
}
