/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:36:13 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/16 10:36:50 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>

typedef struct s_tool {
	int		infile_fd;
	int		outfile_fd;
	int		status;
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
}	t_tool;

/* MAIN FUNCTION */
int		main(int ac, char **av, char **env);

/* HELPER FUNCTION */
void	free_all(char **s);

/* CHECK FUNCTIONS */
int		init_processes(t_tool *tool, char **av, char **env);
void	valid_files(t_tool *tool, char **av);

/* CHILDREN HANDLING */
int		execute_command(char **cmd_args, char **env);
int		handle_first_child(t_tool *tool, char **av, char **env);
int		handle_second_child(t_tool *tool, char **av, char **env);

/* COMMAND PATH */
char	*my_getenv(char *name, char **env);
char	*join_paths(char *cmd, char **env_path);
char	*find_command(char *cmd, char **env);

#endif