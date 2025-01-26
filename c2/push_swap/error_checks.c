/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:25:38 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/26 18:04:12 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_arg(char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

int	is_invalid_num(char *s)
{
	long	res;
	char	*tmp;

	if (!s || !*s)
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	tmp = s;
	if (!*s)
		return (1);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	ft_atoi(tmp, &res);
	if (res > INT_MAX || res < INT_MIN)
		return (1);
	return (0);
}

int	is_dup(char **all_val)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (all_val[i])
	{
		ft_atoi(all_val[i], &num_i);
		j = i + 1;
		while (all_val[j])
		{
			ft_atoi(all_val[j], &num_j);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
