#include "libftprintf.h"

static int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	num;

	num = n;
	len = ft_length(num);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (num == 0)
		s[0] = '0';
	else if (num < 0)
	{
		s[0] = '-';
		num *= -1;
	}
	while (num)
	{
		s[--len] = num % 10 + 48;
		num /= 10;
	}
	return (s);
}
