#include "so_long.h"

char	**store_map(int map_fd)
{
	char	*line;
	char	**map_2d;

	line = get_next_line(map_fd);
	while (line)
	{
		map_2d = ft_strdup(line);
		line = get_next_line(map_fd);
	}
	map_2d = NULL;
	return (map_2d);
}

int	valid_map_file(char *map)
{
	int		map_fd;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		return (ft_putstr_fd("Error\nMap doesn't exist\n", 2), 0);
	
}

int	valid_map_name(char *map)
{
	int	i;

	if (!map || !*map)
		return (0);
	i = 0;
	while (map[i])
	{
		if (map[i] == '.')
			break;
		i++;
	}
	if (i > 0)
	{
		if (ft_strncmp(&map[i], ".ber", 5) == 0)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !valid_map_name(av[1]))
		return (ft_putstr_fd("Not valid\n", 2), 1);
	ft_putstr_fd("map name is valid\n", 1);

	
}
