#include "so_long.h"

int	road_check(t_game tool, int x, int y)
{
	// finish later
	road_check(tool, tool.x + 1, tool.y);
	road_check(tool, tool.x - 1, tool.y);
	road_check(tool, tool.x, tool.y + 1);
	road_check(tool, tool.x, tool.y - 1);
}

int	main(int ac, char **av)
{
	t_game	tool;
	t_count	counter;

	if (ac != 2 || !valid_map_name(av[1])
		|| !valid_map_file(av[1], &tool, &counter))
		return (1);
	// free_arr2d(tool.map_2d);
	ft_putstr_fd("NOICE HEHE\n", 1);
}
