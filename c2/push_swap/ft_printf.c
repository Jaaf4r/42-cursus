#include "ps.h"

int	ft_char_str(int c, char *s)
{
    if (s == NULL)
        return (write(1, "(null)", 6));
    else if (s == (char *)-1)
        return (write(1, &c, 1));
    else
    {
        int len = 0;
        while (s[len])
            len++;
        return (write(1, s, len));
    }
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
		return (c + ft_char_str(nums[n], (char *)-1));
	else
	{
		c += ft_digit(n / base, base, uplowcase, 0);
		return (c + ft_char_str(nums[n % base], (char *)-1));
	}
}

int	handle_format(char format, va_list args)
{
	unsigned long	p;

	if (format == 'c')
		return (ft_char_str(va_arg(args, int), (char *)-1));
	else if (format == 's')
		return (ft_char_str(0, va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_digit(va_arg(args, int), 10, 0, 1));
	else if (format == 'u')
		return (ft_digit(va_arg(args, unsigned int), 10, 0, 0));
	else if (format == 'p')
	{
		p = (unsigned long)va_arg(args, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_digit(p, 16, 0, 0));
	}
	else if (format == 'x')
		return (ft_digit(va_arg(args, unsigned int), 16, 0, 0));
	else if (format == 'X')
		return (ft_digit(va_arg(args, unsigned int), 16, 1, 0));
	return (write(1, "%", 1) + ft_char_str(format, (char *)-1));
}

int	process_format(const char **format, va_list args)
{
	int	n;

	n = 0;
	if (**format == '%' && *(*format + 1) == '\0')
		return (-1);
	if (**format == '%')
	{
		(*format)++;
		if (**format == '%')
			n += write(1, "%", 1);
		else
			n += handle_format(**format, args);
	}
	else
		n += ft_char_str(**format, (char *)-1);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		res;

	if (!format)
		return (-1);
	len = 0;
	va_start(args, format);
	while (*format)
	{
		res = process_format(&format, args);
		if (res == -1)
		{
			va_end(args);
			return (-1);
		}
		len += res;
		format++;
	}
	va_end(args);
	return (len);
}