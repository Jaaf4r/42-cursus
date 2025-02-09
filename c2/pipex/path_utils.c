/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:50:09 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/09 22:50:10 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**init_paths(void)
{
	char	*path_env;
	char	**paths;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	return (paths);
}

static char	*try_path_combinations(char **paths, char *cmd)
{
	int		i;
	char	*full_path;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (access(cmd_path, X_OK) == 0)
			return (free_all(paths), cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**paths;

	if (!cmd || !env)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	paths = init_paths();
	if (!paths)
		return (NULL);
	return (try_path_combinations(paths, cmd));
}
