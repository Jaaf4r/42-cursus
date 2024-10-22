#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int	main()
{
	printf("%d\n%d\n%d\n", ft_isascii(20), ft_isascii(127), ft_isascii(299));
}
*/