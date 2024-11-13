#include "ft_printf.h"

int	handle_format(char format, va_list args)
{
	unsigned long	p;

	if (format == 'c')
		return (ft_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_str(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_digit(va_arg(args, int), 10, 0, 1));
	else if (format == 'u')
		return (ft_digit(va_arg(args, unsigned int), 10, 0, 0));
	else if (format == 'x')
		return (ft_digit(va_arg(args, unsigned int), 16, 0, 0));
	else if (format == 'X')
		return (ft_digit(va_arg(args, unsigned int), 16, 1, 0));
	else if (format == 'p')
	{
		p = (unsigned long)va_arg(args, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_digit(p, 16, 0, 0));
	}
	else
		return (write(1, "%", 1) + ft_char(format));
		
}

int	process_format(const char **format, va_list args)
{
	int	l;

	l = 0;
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			if (**format == '%')
				l += write(1, "%", 1);
			else
				l += handle_format(**format, args);
		}
		else
			l += write(1, *format, 1);
		(*format)++;
	}
	return (l);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		l;

	l = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	l += process_format(&format, args);
	va_end(args);
	return (l);
}
