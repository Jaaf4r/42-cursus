#include "so_long.h"

static int	valid_rectangular_size(t_game *tool)
{
	int	i;

	i = 1;
	while (tool->map_2d[i])
	{
		if (ft_strlen(tool->map_2d[i - 1]) != ft_strlen(tool->map_2d[i]))
			return (ft_putstr_fd("Error\nMap rows are not the same size\n", 2)
				, 0);
		i++;
	}
	tool->line_length = (int)ft_strlen(tool->map_2d[0]);
	if (tool->line_count >= tool->line_length)
		return (ft_putstr_fd("Error\nMap shape is not a rectangle", 2), 0);
	return (1);
}

static int	up_down_walls(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_map_characters(t_game *tool, char *s, int y)
{
	int	i;

	i = 1;
	while (i < tool->line_length - 1)
	{
		if (s[i] == 'P')
		{
			tool->x = i;
			tool->y = y;
			tool->p_count++;
		}
		else if (s[i] == 'E')
			tool->e_count++;
		else if (s[i] == 'C')
			tool->c_count++;
		else if (s[i] != 'P' && s[i] != 'E' && s[i] != 'C' && s[i] != '1'
			&& s[i] != '0')
			return (ft_putstr_fd("Error\nMap contains an unknown character\n", 2)
				, 0);
		i++;
	}
	return (1);
}

static int	check_walls(t_game *tool)
{
	int	i;

	if (!up_down_walls(tool->map_2d[0])
		|| !up_down_walls(tool->map_2d[tool->line_count - 1]))
		return (ft_putstr_fd("Error\nMissing wall\n", 2), 0);
	tool->p_count = 0;
	tool->e_count = 0;
	tool->c_count = 0;
	i = 1;
	while (tool->map_2d[i])
	{
		if (tool->map_2d[i][0] != '1'
			|| tool->map_2d[i][tool->line_length - 1] != '1'
			|| !check_map_characters(tool, tool->map_2d[i], i))
			return (0);
		i++;
	}
	if (tool->p_count != 1 || tool->e_count != 1 || tool->c_count < 1)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 0);
	return (1);
}

int	valid_map_file(char *map, t_game *tool)
{
	if (!valid_map_name(map))
		return (ft_putstr_fd("Error\nMap name is not valid\n", 2), 0);
	count_file_lines(map, tool);
	if (tool->line_count < 3)
	{
		ft_putstr_fd("Error\nMap is too smol xd\n", 2);
		return (free_arr2d(tool->map_2d), 0);
	}
	store_mapfile(map, tool);
	if (!tool->map_2d || !valid_rectangular_size(tool)
		|| !check_walls(tool))
		return (free_arr2d(tool->map_2d), 0);
	return (1);
}
