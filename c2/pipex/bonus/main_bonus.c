/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:35:06 by jabouhni          #+#    #+#             */
/*   Updated: 2025/02/15 12:35:07 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_fd	tools;

	tools.i = 0;
	tools.infile_fd = -1;
	tools.status = 0;
	if (ac < 5)
		return (ft_putstr_fd("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 2)
			, 1);
	if (ft_strncmp("here_doc", av[1], 9) == 0)
	{
		if (heredoc_infile_opening(ac, av, &tools))
			return (1);
		tools.i = 3;
		tools.heredoc_flag = 1;
		handle_pipes(ac, av, env, &tools);
	}
	else
	{
		tools.i = 2;
		tools.heredoc_flag = 0;
		handle_pipes(ac, av, env, &tools);
	}
	return (0);
}
