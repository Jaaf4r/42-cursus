/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:17:52 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/12 01:22:47 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>

int		main(int ac, char **av, char **env);

void	valid_files(int *infile_fd, int *outfile_fd, char **av);
void	free_all(char **s);

int		init_processes(int *file_fd, int *pipefd, char **av, char **env);
int		handle_first_child(int *file_fd, int *pipefd, char **av, char **env);
int		handle_second_child(int *pipefd, int *file_fd, char **av, char **env);

int		valid_path(char **av, char **env, int i, char **cmd);
int		handle_absolute_path(char **cmd, char *cmd_str);
int		path_search(char **cmd_args, char **cmd);
char	**get_env_path(void);
char	*find_cmd_path(char *command, char **env_path);

#endif