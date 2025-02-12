/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:17:55 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/12 01:17:56 by jabouhni         ###   ########.fr       */
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
