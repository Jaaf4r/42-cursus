/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:36:09 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/15 15:04:56 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_fd {
	int		infile_fd;
	int		outfile_fd;
	pid_t	pid;
	int		pipefd[2];
	int		status;
	int		i;
	int		heredoc_flag;
}	t_fd;

/* MAIN FUNCTION */
int		main(int ac, char **av, char **env);

/* HELPER FUNCTION */
void	free_all(char **s);

/* FIND AND EXECUTE COMMANDS */
char	**get_env_path(void);
char	*join_paths(char *cmd, char **env_path);
char	*find_command(char *cmd);
int		execute_command(char *cmd, char **env, int in_fd, int out_fd);

/* MULTIPLE PIPES HANDLING */
void	all_pipes_exc_last(int ac, char **av, char **env, t_fd *tools);
void	last_pipe(int ac, char **av, char **env, t_fd *tools);
int		handle_pipes(int ac, char **av, char **env, t_fd *tools);
int		heredoc_infile_opening(int ac, char **av, t_fd *tools);
int		handle_heredoc(char *limiter, t_fd *tools);

#endif