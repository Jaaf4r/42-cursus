/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:26:03 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:26:06 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_all_val(char **av, char **all_val)
{
	int		i;
	int		j;
	char	**vessel;
	int		all_i;

	i = 0;
	all_i = 0;
	while (av[++i])
	{
		vessel = ft_split(av[i], ' ');
		if (!vessel)
			return (free(all_val), NULL);
		j = 0;
		while (vessel[j])
		{
			all_val[all_i] = ft_strdup(vessel[j]);
			if (!all_val[all_i])
				return (free_all(vessel), free_all(all_val), NULL);
			j++;
			all_i++;
		}
		free_all(vessel);
	}
	return (all_val[all_i] = NULL, all_val);
}

char	**parse_input(char **av)
{
	int		i;
	int		total_count;
	char	**all_val;

	i = 0;
	total_count = 0;
	while (av[++i])
	{
		if (is_empty_arg(av[i]))
			return (NULL);
		total_count += count_words(av[i], ' ');
	}
	all_val = malloc(sizeof(char *) * (total_count + 1));
	if (!all_val)
		return (NULL);
	all_val = fill_all_val(av, all_val);
	i = 0;
	while (all_val[i])
	{
		if (is_invalid_num(all_val[i++]))
			return (free_all(all_val), NULL);
	}
	if (is_dup(all_val))
		return (free_all(all_val), NULL);
	return (all_val);
}
