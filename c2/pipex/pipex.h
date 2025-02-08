#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <sys/wait.h>

int		main(int ac, char **av, char **env);

void	free_all(char **ss);

#endif