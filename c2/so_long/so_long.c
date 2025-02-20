#include "so_long.h"

void	free_arr2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	count_file_lines(char *map, t_game *tool)
{
	tool->map_fd = open(map, O_RDONLY);
	if (tool->map_fd == -1)
	{
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
		exit(1);
	}
	tool->line_count = 0;
	tool->line = get_next_line(tool->map_fd);
	while (tool->line)
	{
		tool->line_count++;
		tool->line = get_next_line(tool->map_fd);
	}
	close(tool->map_fd);
}

char	**store_map(char *map, t_game *tool)
{
	int	i;

	i = 0;
	tool->map_fd = open(map, O_RDONLY);
	if (tool->map_fd == -1)
	{
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
		exit(1);
	}
	tool->map_2d = malloc(sizeof(char *) * (tool->line_count + 1));
	if (!tool->map_2d)
		return (close(tool->map_fd), NULL);
	tool->line = get_next_line(tool->map_fd);
	while (tool->line)
	{
		if (tool->line[ft_strlen(tool->line) - 1] == '\n')
			tool->line[ft_strlen(tool->line) - 1] = '\0';
		tool->map_2d[i++] = ft_strdup(tool->line);
		if (!tool->map_2d[i - 1])
			return (free(tool->line), free_arr2d(tool->map_2d), NULL);
		tool->line = get_next_line(tool->map_fd);
	}
	tool->map_2d[i] = NULL;
	close(tool->map_fd);
	return (tool->map_2d);
}

int	valid_rectangular_size(t_game *tool)
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
		return (printf("line count: %d | line length: %d\n", tool->line_count, tool->line_length), ft_putstr_fd("Error\nMap shape is not a rectangle", 2), 0);
	return (1);
}

int	up_down_walls(char *s)
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

int	check_map_characters(t_game *tool, char *s, t_flag *flags)
{
	int	i;

	(i = 1), flags->p_flag = 0, flags->e_flag = 0, flags->c_flag = 2;
	while (i < tool->line_length - 1)
	{
		if (flags->p_flag == 0 && s[i] == 'P')
			flags->p_flag = 1;
		else if (flags->e_flag == 0 && s[i] == 'E')
			flags->e_flag = 1;
		else if (s[i] == 'C')
			flags->c_flag = 1;
		else if (s[i] == '1' || s[i] == '0')
			mazal hna khawi
		// else if (flags->p_flag == 1 && tool->map_2d == 'P'
		// 	|| flags->e_flag == 1 && tool->map_2d == 'E')
		// 	return (0);
		else
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *tool, t_flag *flags)
{
	int	i;

	i = 0;
	if (!up_down_walls(tool->map_2d[0])
		|| !up_down_walls(tool->map_2d[tool->line_count - 1]))
		return (0);
	while (tool->map_2d[i] && i < tool->line_count - 2)
	{
		if (tool->map_2d[i][0] != '1' || tool->map_2d[i][tool->line_length - 1] != '1'
			|| !check_map_characters(tool, tool->map_2d[i], flags))
			return (0);
		i++;
	}
	exit(1);
	return (1);
}

int	valid_map_file(char *map, t_game *tool, t_flag *flags)
{
	count_file_lines(map, tool);
	if (tool->line_count < 3)
	{
		ft_putstr_fd("Error\nMap is too smol xd\n", 2);
		return (0);
	}
	tool->map_2d = store_map(map, tool);
	if (!tool->map_2d || !valid_rectangular_size(tool)
		|| !check_walls(tool, flags))
		return (0);
	return (1);
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
			break ;
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
	t_game	tool;
	t_flag	flags;

	if (ac != 2 || !valid_map_name(av[1]) || !valid_map_file(av[1], &tool, &flags))
		return (1);
	ft_putstr_fd("NOICE HEHE\n", 1);
}
