/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:17:47 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/12 01:17:48 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_first_child(int *file_fd, int *pipefd, char **av, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	if (file_fd[0] != -1)
	{
		dup2(file_fd[0], STDIN_FILENO);
		close(file_fd[0]);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(file_fd[1]);
	close(pipefd[0]);
	cmd_args = ft_split(av[2], ' ');
	if (!cmd_args || !valid_path(av, env, 2, &cmd_path))
		exit(1);
	execve(cmd_path, cmd_args, env);
	free_all(cmd_args);
	free(cmd_path);
	exit(127);
}

int	handle_second_child(int *pipefd, int *file_fd, char **av, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	dup2(pipefd[0], STDIN_FILENO);
	dup2(file_fd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(file_fd[1]);
	close(file_fd[0]);
	close(pipefd[1]);
	cmd_args = ft_split(av[3], ' ');
	if (!cmd_args || !valid_path(av, env, 3, &cmd_path))
		exit(1);
	execve(cmd_path, cmd_args, env);
	free_all(cmd_args);
	free(cmd_path);
	exit(127);
}

int	init_processes(int *file_fd, int *pipefd, char **av, char **env)
{
	pid_t	pid[2];

	pid[0] = fork();
	if (pid[0] == -1)
		return (perror("Fork error"), 1);
	if (pid[0] == 0)
		handle_first_child(file_fd, pipefd, av, env);
	pid[1] = fork();
	if (pid[1] == -1)
		return (perror("Fork error"), 1);
	if (pid[1] == 0)
		handle_second_child(pipefd, file_fd, av, env);
	close(pipefd[0]);
	close(pipefd[1]);
	close(file_fd[0]);
	close(file_fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
