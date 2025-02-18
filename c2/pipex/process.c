/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:39:03 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/16 11:25:26 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_command(char **cmd_args, char **env)
{
	char	*cmd_path;

	cmd_path = find_command(cmd_args[0], env);
	if (!cmd_path)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		free_all(cmd_args);
		exit(127);
	}
	execve(cmd_path, cmd_args, env);
	perror("execve");
	free_all(cmd_args);
	free(cmd_path);
	exit(127);
}

int	handle_first_child(t_tool *tool, char **av, char **env)
{
	char	**cmd_args;

	if (tool->infile_fd == -1)
	{
		close(tool->pipefd[0]);
		close(tool->pipefd[1]);
		close(tool->outfile_fd);
		exit(1);
	}
	dup2(tool->infile_fd, STDIN_FILENO);
	close(tool->infile_fd);
	dup2(tool->pipefd[1], STDOUT_FILENO);
	close(tool->pipefd[1]);
	close(tool->outfile_fd);
	close(tool->pipefd[0]);
	cmd_args = ft_split(av[2], ' ');
	if (!cmd_args)
		exit(1);
	return (execute_command(cmd_args, env));
}

int	handle_second_child(t_tool *tool, char **av, char **env)
{
	char	**cmd_args;

	dup2(tool->pipefd[0], STDIN_FILENO);
	dup2(tool->outfile_fd, STDOUT_FILENO);
	close(tool->pipefd[0]);
	close(tool->outfile_fd);
	close(tool->infile_fd);
	close(tool->pipefd[1]);
	cmd_args = ft_split(av[3], ' ');
	if (!cmd_args)
		exit(1);
	return (execute_command(cmd_args, env));
}
