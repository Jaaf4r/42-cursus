/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_pipes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:35:57 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/15 15:00:17 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	all_pipes_exc_last(int ac, char **av, char **env, t_fd *tools)
{
	while (tools->i < ac - 2)
	{
		if (pipe(tools->pipefd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		tools->pid = fork();
		if (tools->pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (tools->pid == 0)
		{
			close(tools->pipefd[0]);
			execute_command(av[tools->i], env,
				tools->infile_fd, tools->pipefd[1]);
		}
		close(tools->pipefd[1]);
		if (tools->infile_fd != -1)
			close(tools->infile_fd);
		tools->infile_fd = tools->pipefd[0];
		tools->i++;
	}
}

void	last_pipe(int ac, char **av, char **env, t_fd *tools)
{
	int	out_fd;

	tools->pid = fork();
	if (tools->pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (tools->pid == 0)
	{
		out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd == -1)
		{
			perror(av[ac - 1]);
			exit(1);
		}
		execute_command(av[ac - 2], env, tools->infile_fd, out_fd);
	}
	if (tools->infile_fd != -1)
		close(tools->infile_fd);
}

int	handle_pipes(int ac, char **av, char **env, t_fd *tools)
{
	if (!tools)
		return (1);
	if (tools->heredoc_flag == 0)
	{
		tools->infile_fd = open(av[1], O_RDONLY);
		if (tools->infile_fd == -1)
			perror(av[1]);
	}
	all_pipes_exc_last(ac, av, env, tools);
	last_pipe(ac, av, env, tools);
	while (waitpid(tools->pid, &tools->status, 0) > 0)
		;
	return (WEXITSTATUS(tools->status));
}

int	heredoc_infile_opening(int ac, char **av, t_fd *tools)
{
	if (ac < 6)
		return (ft_putstr_fd("./pipex here_doc LIMITER cmd cmd1 file", 2), 1);
	tools->infile_fd = handle_heredoc(av[2], tools);
	if (tools->infile_fd == -1)
		return (1);
	tools->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tools->outfile_fd == -1)
	{
		perror(av[ac - 1]);
		return (1);
	}
	return (0);
}

int	handle_heredoc(char *limiter, t_fd *tools)
{
	char	*line;

	if (pipe(tools->pipefd) == -1)
		return (-1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0
			&& (line[ft_strlen(limiter)] == '\n'))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, tools->pipefd[1]);
		free(line);
	}
	close(tools->pipefd[1]);
	return (tools->pipefd[0]);
}
