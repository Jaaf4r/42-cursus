#include "ft_printf.h"

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *s)
{
	int l;

	l = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s, 1);
		s++;
		l++;
	}
	return (l);
}

int	ft_digit(unsigned long n, int base, int uppcase, int is_signed)
{
	int		l;
	char	*arr;

	l = 0;
	if (uppcase == 1)
		arr = "0123456789ABCDEF";
	else
		arr = "0123456789abcdef";
	if (is_signed && (long)n < 0)
	{
		l += write(1, "-", 1);
		n = -n;
	}
	if (n < base)
		return (l + ft_char(arr[n]));
	else
	{
		l += ft_digit(n / base, base, uppcase, 0);
		return (l + ft_char(arr[n % base]));
	}
}
