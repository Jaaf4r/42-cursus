/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:08:19 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/10 22:08:20 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *s)
{
	int	c;

	if (!s)
		s = "(null)";
	c = 0;
	while (*s)
	{
		write(1, s, 1);
		c++;
		s++;
	}
	return (c);
}

int	ft_digit(long n, int base, int uplowcase)
{
	int		c;
	char	*nums;

	c = 0;
	if (uplowcase == 1)
		nums = "0123456789ABCDEF";
	else
		nums = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_digit(-n, base, uplowcase) + 1);
	}
	if (n < base)
		return (ft_char(nums[n]));
	else
	{
		c += ft_digit(n / base, base, uplowcase);
		return (c + ft_char(nums[n % base]));
	}
}
