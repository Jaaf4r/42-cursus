/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:49:42 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/09 22:49:43 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_command_path(char **cmd_args, char **env)
{
	char	*cmd_path;

	cmd_path = get_path(cmd_args[0], env);
	if (!cmd_path)
	{
		perror("Command not found\n");
		free_all(cmd_args);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	perror("execve failed\n");
	free_all(cmd_args);
	free(cmd_path);
	exit(1);
}

void	execute_command(char *cmd, char **env)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
	{
		free_all(cmd_args);
		exit(127);
	}
	handle_command_path(cmd_args, env);
}
