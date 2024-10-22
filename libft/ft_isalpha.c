#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c<= 'z'))
		return (1);
	else
		return (0);
}

/*
int	main()
{
	printf("%d\n%d\n%d\n", ft_isalpha('c'), ft_isalpha('.'), ft_isalpha('Z'));
}
*/