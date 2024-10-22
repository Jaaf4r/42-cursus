#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
int	main()
{
	printf("%d\n%d\n%d\n", ft_isalnum('c'), ft_isalnum('4'), ft_isalnum('.'));
}*/