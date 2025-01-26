/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:25:52 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/26 23:49:08 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	free_all(char **ss)
{
	int	i;

	if (!ss)
		return ;
	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
}

static int	ft_space_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

bool	ft_atoi(char *s, long *total)
{
	int		i;
	long	res;
	int		sign;

	if (!s)
		return (false);
	res = 0;
	i = 0;
	sign = ft_space_sign(s, &i);
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && res > (long)INT_MAX + 1))
			return (false);
		i++;
	}
	*total = res * sign;
	if (*total < INT_MIN || *total > INT_MAX)
		return (false);
	return (true);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
