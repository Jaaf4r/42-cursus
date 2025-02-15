/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:36:13 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/15 12:36:14 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>

/* MAIN FUNCTION */
int		main(int ac, char **av, char **env);

/* HELPER FUNCTION */
void	free_all(char **s);

/* CHECK FUNCTIONS */
int		init_processes(int *file_fd, char **av, char **env);
void	valid_files(int *infile_fd, int *outfile_fd, char **av);

/* CHILDREN HANDLING */
int		execute_command(char **cmd_args, char **env);
int		handle_first_child(int *file_fd, int *pipefd, char **av, char **env);
int		handle_second_child(int *pipefd, int *file_fd, char **av, char **env);

/* COMMAND PATH */
char	**get_env_path(void);
char	*join_paths(char *cmd, char **env_path);
char	*find_command(char *cmd);

#endif