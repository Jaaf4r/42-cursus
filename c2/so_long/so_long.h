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
	int		index;
	int		p_count;
	int		e_count;
	int		c_count;
	int		x;
	int		y;
}	t_game;

int		main(int ac, char **av);

void	free_arr2d(char **arr);
int		valid_map_name(char *map);
void	count_file_lines(char *map, t_game *tool);
void	open_andstore_mapfile(char *map, t_game *tool);

int		valid_rectangular_size(t_game *tool);
int		up_down_walls(char *s);
int		check_map_characters(t_game *tool, char *s, int y);
int		check_walls(t_game *tool);
int		valid_map_file(char *map, t_game *tool);

#endif