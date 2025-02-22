#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "/usr/include/minilibx-linux/mlx.h"

typedef struct s_game
{
	int		map_fd;
	char	*line;
	char	**map_2d;
	int		line_count;
	int		line_length;
}	t_game;

typedef struct s_count
{
	int	p_count;
	int	e_count;
	int	c_count;
}	t_count;

int		main(int ac, char **av);

void	free_arr2d(char **arr);

int		valid_map_name(char *map);
int		valid_map_file(char *map, t_game *tool, t_count *counter);
char	**store_map(char *map, t_game *tool);
void	count_file_lines(char *map, t_game *tool);
int		valid_rectangular_size(t_game *tool);

#endif