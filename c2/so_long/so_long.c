#include "so_long.h"

void	road_check(t_game *tool, int x, int y)
{
	int	c;

	c = 0;
	if (c == tool->c_count && tool->map_2d[x] == 'E')
		return ;
	if (tool->map_2d[x][y] == 'C')
		c++;
	// finish later

	road_check(tool, tool->x + 1, tool->y);
	road_check(tool, tool->x - 1, tool->y);
	road_check(tool, tool->x, tool->y + 1);
	road_check(tool, tool->x, tool->y - 1);
}

int	main(int ac, char **av)
{
	t_game	tool;

	if (ac != 2 || !valid_map_name(av[1])
		|| !valid_map_file(av[1], &tool))
		return (1);
	road_check(&tool, tool.x, tool.y);
	// free_arr2d(tool.map_2d);
	ft_putstr_fd("NOICE HEHE\n", 1);
}
