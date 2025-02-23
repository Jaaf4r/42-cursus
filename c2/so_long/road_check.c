#include "so_long.h"

static char	**visited_array(t_game *tool)
{
	char	**visited;

	int (i), (j);
	visited = malloc(sizeof(char *) * tool->line_count);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < tool->line_count)
	{
		visited[i] = malloc(sizeof(char) * tool->line_length);
		if (!visited[i])
		{
			while (--i > 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		j = 0;
		while (j < tool->line_length)
			visited[i][j++] = '0';
		i++;
	}
	return (visited);
}

static void	check_all_paths(t_game *tool, int x, int y, char **visited)
{
	if (x < 0 || x >= tool->line_count || y < 0 || y >= tool->line_length)
		return ;
	if (tool->map_2d[x][y] == '1' || visited[x][y] == '1')
		return ;

	visited[x][y] = '1';
	if (tool->map_2d[x][y] == 'C')
		tool->collectibles++;

	check_all_paths(tool, x + 1, y, visited);
	check_all_paths(tool, x - 1, y, visited);
	check_all_paths(tool, x, y + 1, visited);
	check_all_paths(tool, x, y - 1, visited);
}

static void	free_visited_arr(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

static int	valid_path(t_game *tool)
{
	char	**visited;

	int	(i), (j), (exit_reachable);
	visited = visited_array(tool);
	if (!visited)
		return (0);
	tool->collectibles = 0;
	check_all_paths(tool, tool->x, tool->y, visited);
	i = 0;
	exit_reachable = 0;
	while (i < tool->line_count)
	{
		j = 0;
		while (j < tool->line_length)
		{
			if (tool->map_2d[i][j] == 'E' && visited[i][j] == '1')
				exit_reachable = 1;
			j++;
		}
		i++;
	}
	free_visited_arr(visited, tool->line_count);
	if (!exit_reachable)
		return (ft_putstr_fd("Error\nExit is not reachable\n", 2), 0);
	if (tool->collectibles != tool->c_count)
		return (ft_putstr_fd("Error\nNot all collectibles are reachable\n", 2), 0);
	return (1);
}

void    road_check(t_game *tool)
{
	if (!valid_path(tool))
	{
		free_arr2d(tool->map_2d);
		exit(1);
	}
}
