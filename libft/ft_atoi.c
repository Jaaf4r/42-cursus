#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	sign = 1;
	int	num = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}

/*
int	main()
{
	printf("%d\n", atoi("    -123abc"));
	printf("%d\n", ft_atoi("    -123abc"));
}
*/