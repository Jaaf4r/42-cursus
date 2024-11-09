#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;

	if (!format)
		return ;
	va_start(args, char *);
	while (*format)
	{
		if (*(format - 1) == '%' && *format == 'c')
			write(1, );
		format++;
	}
}
