/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:37 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/04 12:56:17 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;
	int			digit;

	i = 0;
	num = 0;
	sign = ft_space_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - 48;
		if (sign == 1 && (num > (LLONG_MAX - digit) / 10))
			return (-1);
		if (sign == -1 && (-num < (LLONG_MIN + digit) / 10))
			return (0);
		num = num * 10 + digit;
		i++;
	}
	return (num * sign);
}
