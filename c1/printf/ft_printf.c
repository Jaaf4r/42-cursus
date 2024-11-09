#include "libftprintf.h"

static void	ft_dics(const char *format, va_list *args)
{
	int		n;
	char	*buffer;
	char	c;

	if (*format == 'd' || *format == 'i')
	{
		n = va_arg(*args, int);
		buffer = ft_itoa(n);
		write(1, buffer, ft_strlen(buffer));
	}
	else if (*format == 'c')
	{
		c = (char)va_arg(*args, int);
		write(1, &c, 1);
	}
	else if (*format == 's')
	{
		buffer = va_arg(*args, char *);
		write(1, buffer, ft_strlen(buffer));
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 'd' || *format == 'i')
				ft_dics(format, &args);
			else if (*format == 's')
				ft_dics(format, &args);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

int	main()
{
	ft_printf("alo %s 3alaykom, %% lyom %d f shher %covember", "salamo", 9, 'N');
}
