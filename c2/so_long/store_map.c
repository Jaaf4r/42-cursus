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
		free(tool->line);
		tool->line = get_next_line(tool->map_fd);
	}
	close(tool->map_fd);
}

static void	store_map_2d_arr(t_game *tool)
{
	tool->map_2d = malloc(sizeof(char *) * (tool->line_count + 1));
	if (!tool->map_2d)
	{
		close(tool->map_fd);
		return ;
	}
	tool->index = 0;
	tool->line = get_next_line(tool->map_fd);
	while (tool->line)
	{
		if (tool->line[ft_strlen(tool->line) - 1] == '\n')
			tool->line[ft_strlen(tool->line) - 1] = '\0';
		tool->map_2d[tool->index] = ft_strdup(tool->line);
		if (!tool->map_2d[tool->index])
		{
			free(tool->line);
			free_arr2d(tool->map_2d);
		}
		tool->index++;
		free(tool->line);
		tool->line = get_next_line(tool->map_fd);
	}
	tool->map_2d[tool->index] = NULL;
}

void	store_mapfile(char *map, t_game *tool)
{
	tool->map_fd = open(map, O_RDONLY);
	if (tool->map_fd == -1)
	{
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
		exit(1);
	}
	store_map_2d_arr(tool);
	close(tool->map_fd);
}
