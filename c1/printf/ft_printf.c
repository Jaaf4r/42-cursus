/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:08:12 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/10 22:18:21 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_str(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_digit(va_arg(args, int), 10, 0));
	else if (format == 'u')
		return (ft_digit(va_arg(args, unsigned int), 10, 0));
	else if (format == 'p')
	{
		return (write(1, "0x", 2)
			+ ft_digit(va_arg(args, unsigned long), 16, 0));
	}
	else if (format == 'x')
		return (ft_digit(va_arg(args, unsigned long), 16, 0));
	else if (format == 'X')
		return (ft_digit(va_arg(args, unsigned long), 16, 1));
	return (write(1, "%", 1) + ft_char(format));
}

int	process_format(const char **format, va_list args)
{
	int	n;

	n = 0;
	if (**format == '%')
	{
		if (**format == '\0')
		{
			va_end(args);
			return (-1);
		}
		(*format)++;
		if (**format == '%')
			n += write(1, "%", 1);
		else
			n += handle_format(**format, args);
	}
	else
		n += ft_char(**format);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		len += process_format(&format, args);
		format++;
	}
	va_end(args);
	return (len);
}
