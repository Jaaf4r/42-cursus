/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:17:50 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/12 01:17:51 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	file_fd[2];
	int	pipefd[2];

	if (ac != 5)
		return (1);
	valid_files(&file_fd[0], &file_fd[1], av);
	if (pipe(pipefd) == -1)
		return (perror("Pipe error"), 1);
	return (init_processes(file_fd, pipefd, av, env));
}
