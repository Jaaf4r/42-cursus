/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:38:10 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/16 09:07:59 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	valid_files(t_tool *tool, char **av)
{
	tool->infile_fd = open(av[1], O_RDONLY);
	if (tool->infile_fd == -1)
		perror(av[1]);
	tool->outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tool->outfile_fd == -1)
	{
		perror(av[4]);
		close(tool->infile_fd);
		exit(1);
	}
}

int	init_processes(t_tool *tool, char **av, char **env)
{
	if (pipe(tool->pipefd) == -1)
		return (perror("pipe"), 1);
	tool->pid1 = fork();
	if (tool->pid1 == -1)
		return (perror("fork"), 1);
	if (tool->pid1 == 0)
		handle_first_child(tool, av, env);
	close(tool->pipefd[1]);
	tool->pid2 = fork();
	if (tool->pid2 == -1)
		return (perror("fork"), 1);
	if (tool->pid2 == 0)
		handle_second_child(tool, av, env);
	close(tool->pipefd[0]);
	close(tool->infile_fd);
	close(tool->outfile_fd);
	waitpid(tool->pid1, &tool->status, 0);
	waitpid(tool->pid2, &tool->status, 0);
	return (WEXITSTATUS(tool->status));
}

int	main(int ac, char **av, char **env)
{
	t_tool	tool;

	if (ac != 5)
		return (1);
	valid_files(&tool, av);
	return (init_processes(&tool, av, env));
}
