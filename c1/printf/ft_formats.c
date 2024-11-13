/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:08:19 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/13 11:19:55 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[l])
		l++;
	return (write(1, s, l));
}

int	ft_digit(unsigned long n, int base, int uplowcase, int is_signed)
{
	int		c;
	char	*nums;

	c = 0;
	if (uplowcase == 1)
		nums = "0123456789ABCDEF";
	else
		nums = "0123456789abcdef";
	if (is_signed && (long)n < 0)
	{
		c += write(1, "-", 1);
		n = -n;
	}
	if (n < (unsigned long)base)
		return (c + ft_char(nums[n]));
	else
	{
		c += ft_digit(n / base, base, uplowcase, 0);
		return (c + ft_char(nums[n % base]));
	}
}
