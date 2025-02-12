/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:17:43 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/12 01:19:01 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_absolute_path(char **cmd, char *cmd_str)
{
	*cmd = ft_strdup(cmd_str);
	if (!*cmd)
		return (0);
	return (1);
}

int	path_search(char **cmd_args, char **cmd)
{
	char	**env_path;
	char	*cmd_path;

	env_path = get_env_path();
	if (!env_path)
		return (free_all(cmd_args), 0);
	cmd_path = find_cmd_path(cmd_args[0], env_path);
	if (cmd_path)
	{
		*cmd = ft_strdup(cmd_path);
		free(cmd_path);
		if (!*cmd)
			return (free_all(cmd_args), free_all(env_path), 0);
		return (free_all(cmd_args), free_all(env_path), 1);
	}
	ft_putstr_fd("Command not found\n", 2);
	return (free_all(cmd_args), free_all(env_path), 0);
}

int	valid_path(char **av, char **env, int i, char **cmd)
{
	char	**cmd_args;

	if (!env)
		return (0);
	if (access(av[i], X_OK) == 0)
		handle_absolute_path(cmd, av[i]);
	cmd_args = ft_split(av[i], ' ');
	if (!cmd_args)
		return (0);
	return (path_search(cmd_args, cmd));
}

char	**get_env_path(void)
{
	char	*tmp;
	char	**env_path;

	tmp = getenv("PATH");
	if (!tmp)
		return (NULL);
	env_path = ft_split(tmp, ':');
	if (!env_path)
		return (NULL);
	return (env_path);
}

char	*find_cmd_path(char *command, char **env_path)
{
	int		k;
	char	*tmp;
	char	*cmd_path;

	k = 0;
	while (env_path[k])
	{
		tmp = ft_strjoin(env_path[k], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, command);
		free(tmp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		k++;
	}
	return (NULL);
}
