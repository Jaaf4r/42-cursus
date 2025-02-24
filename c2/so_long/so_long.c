#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	tool;

	ft_bzero(&tool, sizeof(t_game));
	if (ac != 2 || !valid_map_file(av[1], &tool))
		return (1);
	road_check(&tool);
	ft_putstr_fd("NOICE HEHE\n", 1);
	free_arr2d(tool.map_2d);
	return (0);
}
