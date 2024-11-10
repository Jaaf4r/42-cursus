#include "libftprintf.h"

static int ft_char(int c)
{
	return (write(1, &c, 1));
}

static int	ft_str(char *s)
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

static int	ft_digit(long n, int base, int uplowcase)
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

int ft_formats(char format, va_list args)
{
	int		c;

	c = 0;
	if (format == 'c')
		c += ft_char(va_arg(args, int));
	else if (format == 's')
		c += ft_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		c += ft_digit(va_arg(args, int), 10, 0);
	else if (format == 'u')
		c += ft_digit(va_arg(args, unsigned int), 10, 0);
	else if (format == 'p')
	{
		c += write(1, "0x", 2);
		c += ft_digit(va_arg(args, unsigned long), 16, 0);
	}
	else if (format == 'x')
		c += ft_digit(va_arg(args, unsigned long), 16, 0);
	else if (format == 'X')
		c += ft_digit(va_arg(args, unsigned long), 16, 1);
	else
	{
		c += write(1, "%", 1);
		c += write(1, &format, 1);
	}
	return (c);
}
