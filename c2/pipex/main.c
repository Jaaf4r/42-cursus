/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:50:00 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/09 22:50:01 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_files(int file_fd[2], char **av)
{
	file_fd[0] = open(av[1], O_RDONLY);
	if (file_fd[0] == -1)
		perror(av[1]);
	file_fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd[1] == -1)
	{
		perror(av[4]);
		close(file_fd[0]);
		exit(1);
	}
}

void	handle_first_child(int *file_fd, int *pipefd,
							char **av, char **env)
{
	if (file_fd[0] != -1)
	{
		dup2(file_fd[0], STDIN_FILENO);
		close(file_fd[0]);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(file_fd[1]);
	close(pipefd[1]);
	if (file_fd[0] == -1)
		exit(0);
	execute_command(av[2], env);
}

void	handle_second_child(int *pipefd, int *file_fd,
							char **av, char **env)
{
	dup2(pipefd[0], STDIN_FILENO);
	dup2(file_fd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(file_fd[1]);
	close(file_fd[0]);
	close(pipefd[1]);
	execute_command(av[3], env);
}

static int	wait_for_children(pid_t pid1, pid_t pid2)
{
	int	status;

	waitpid(pid1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int		file_fd[2];
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5 || !valid_arg_commands(av, 2) || !valid_arg_commands(av, 3))
		return (1);
	init_files(file_fd, av);
	if (pipe(pipefd) == -1)
		return (perror("Error opening the pipe\n"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Error with fork\n"), 1);
	if (pid1 == 0)
		handle_first_child(file_fd, pipefd, av, env);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Error with fork\n"), 1);
	if (pid2 == 0)
		handle_second_child(pipefd, file_fd, av, env);
	return (close(file_fd[0]), close(file_fd[1]), close(pipefd[0]),
		close(pipefd[1]), wait_for_children(pid1, pid2));
}
