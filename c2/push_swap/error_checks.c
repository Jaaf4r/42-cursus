/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:25:38 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:25:41 by jabouhni         ###   ########.fr       */
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
	char	*normalized;

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
	normalized = normlize_num(tmp);
	if (!normalized)
		return (1);
	ft_atoi(normalized, &res);
	free(normalized);
	if (res > INT_MAX || res < INT_MIN)
		return (1);
	return (0);
}

char	*normlize_num(char *s)
{
	while (*s == '0' && *(s + 1) != '\0')
		s++;
	return (ft_strdup(s));
}

int	is_dup(char **all_val)
{
	int		i;
	int		j;
	char	*norm_i;

	i = 0;
	while (all_val[i])
	{
		norm_i = normlize_num(all_val[i]);
		if (!norm_i)
			return (1);
		free(all_val[i]);
		all_val[i] = norm_i;
		i++;
	}
	i = 0;
	while (all_val[i])
	{
		j = i + 1;
		while (all_val[j])
			if (ft_strcmp(all_val[i], all_val[j++]) == 0)
				return (1);
		i++;
	}
	return (0);
}
