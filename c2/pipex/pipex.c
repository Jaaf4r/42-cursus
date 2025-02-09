/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:50:22 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/09 22:50:23 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_command_check(char **av, int i, char ***cmd_args, char ***env)
{
	char	*path_env;

	*cmd_args = ft_split(av[i], ' ');
	if (!*cmd_args)
		return (printf("Error: Failed to split command\n"), 0);
	path_env = getenv("PATH");
	if (!path_env)
		return (printf("Error: PATH not set\n"), 0);
	*env = ft_split(path_env, ':');
	if (!*env)
		return (free_all(*cmd_args), 0);
	return (1);
}

int	try_path_access(char **env, char **cmd_args)
{
	int		k;
	char	*full_path;
	char	*cmd_path;

	k = 0;
	while (env[k])
	{
		full_path = ft_strjoin(env[k], "/");
		cmd_path = ft_strjoin(full_path, cmd_args[0]);
		free(full_path);
		if (access(cmd_path, X_OK) == 0)
			return (free(cmd_path), free_all(cmd_args), free_all(env), 1);
		free(cmd_path);
		k++;
	}
	return (0);
}

int	valid_arg_commands(char **av, int i)
{
	char	**cmd_args;
	char	**env;

	if (access(av[i], X_OK) == 0)
		return (1);
	if (!init_command_check(av, i, &cmd_args, &env))
		return (0);
	if (try_path_access(env, cmd_args))
		return (1);
	free_all(env);
	printf("Command not found: %s\n", cmd_args[0]);
	free_all(cmd_args);
	return (0);
}
