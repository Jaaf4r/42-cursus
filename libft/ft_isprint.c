#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int	main()
{
	printf("%d\n%d\n%d\n", ft_isdigit('1'), ft_isdigit(67), ft_isdigit(48));
}
*/