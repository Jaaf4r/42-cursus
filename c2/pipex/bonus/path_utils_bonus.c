/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:35:03 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/15 12:35:05 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

char	**get_env_path(void)
{
	char	**paths;
	char	*tmp;

	tmp = getenv("PATH");
	if (!tmp)
		return (NULL);
	paths = ft_split(tmp, ':');
	return (paths);
}

char	*join_paths(char *cmd, char **env_path)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	while (env_path[i])
	{
		tmp = ft_strjoin(env_path[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*find_command(char *cmd)
{
	char	*cmd_path;
	char	**env_path;

	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	env_path = get_env_path();
	if (!env_path)
		return (NULL);
	cmd_path = join_paths(cmd, env_path);
	if (!cmd_path)
		return (free_all(env_path), NULL);
	return (free_all(env_path), cmd_path);
}

int	execute_command(char *cmd, char **env, int in_fd, int out_fd)
{
	char	**cmd_args;
	char	*cmd_path;

	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		exit(1);
	cmd_path = find_command(cmd_args[0]);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		free_all(cmd_args);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	free_all(cmd_args);
	free(cmd_path);
	exit(127);
}
