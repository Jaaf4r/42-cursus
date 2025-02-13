#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/wait.h>

int		main(int ac, char **av, char **env);

void	free_all(char **s);

char	**get_env_path(void);
char	*join_paths(char *cmd, char **env_path);
char	*find_command(char *cmd);

#endif