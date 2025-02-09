/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:51:19 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/09 22:51:52 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

int		main(int ac, char **av, char **env);

void	free_all(char **ss);

int		valid_arg_commands(char **av, int i);
int		init_command_check(char **av, int i, char ***cmd_args, char ***env);
int		try_path_access(char **env, char **cmd_args);

void	init_files(int file_fd[2], char **av);
void	handle_first_child(int *file_fd, int *pipefd,
			char **av, char **env);
void	handle_second_child(int *pipefd, int *file_fd,
			char **av, char **env);

void	execute_command(char *cmd, char **env);
void	handle_command_path(char **cmd_args, char **env);

char	*get_path(char *cmd, char **env);

#endif