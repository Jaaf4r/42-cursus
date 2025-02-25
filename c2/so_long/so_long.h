#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "/usr/include/minilibx-linux/mlx.h"

typedef struct s_game {
	int		map_fd;
	int		tmp_fd;
	char	*line;
	char	*map_1d;
	char	**map_2d;
	int		line_count;
	int		line_length;
	int		p_count;
	int		e_count;
	int		c_count;
	int		x;
	int		y;
	int		collectibles;
	char	**visited;
}	t_game;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		main(int ac, char **av);

void	free_arr2d(char **arr);
int		valid_map_name(char *map);
void	store_mapfile(char *map, t_game *tool);

int		valid_map_file(char *map, t_game *tool);

void	road_check(t_game *tool);

#endif