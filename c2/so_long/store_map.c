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

static void	store_map_1d_arr(t_game *tool)
{
	char	*tmp;

	tool->line = get_next_line(tool->tmp_fd);
	tool->map_1d = ft_strdup("");
	if (!tool->map_1d)
	{
		free(tool->line);
		close(tool->tmp_fd);
		return ;
	}
	while (tool->line)
	{
		tmp = ft_strjoin(tool->map_1d, tool->line);
		free(tool->map_1d);
		free(tool->line);
		if (!tmp)
			return ;
		tool->map_1d = tmp;
		tool->line = get_next_line(tool->tmp_fd);
		tool->line_count++;
	}
}

static void	store_map_2d_arr(char *map, t_game *tool)
{
	tool->tmp_fd = open(map, O_RDONLY);
	if (tool->tmp_fd == -1)
	{
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
		exit(1);
	}
	store_map_1d_arr(tool);
	close(tool->tmp_fd);
	if (tool->map_1d[ft_strlen(tool->map_1d) - 1] == '\n')
	{
		ft_putstr_fd("Error\nNew line(s) at the end\n", 2);
		free(tool->map_1d);
		return ;
	}
	tool->map_2d = ft_split(tool->map_1d, '\n');
	if (!tool->map_2d)
	{
		free(tool->map_1d);
		return ;
	}
	free(tool->map_1d);
}

void	store_mapfile(char *map, t_game *tool)
{
	int	i;

	tool->map_fd = open(map, O_RDONLY);
	if (tool->map_fd == -1)
	{
		ft_putstr_fd("Error\nMap doesn't exist\n", 2);
		exit(1);
	}
	store_map_2d_arr(map, tool);
	if (!tool->map_2d)
	{
		close(tool->map_fd);
		return ;
	}
	i = 0;
	while (tool->map_2d[i])
	{
		tool->line_length = ft_strlen(tool->map_2d[i]);
		if (tool->map_2d[i][tool->line_length - 1] == '\n')
			tool->map_2d[i][tool->line_length - 1] = '\0';
		i++;
	}
	close(tool->map_fd);
}
