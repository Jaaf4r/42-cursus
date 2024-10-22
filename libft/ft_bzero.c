#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i = 0;
	char	*p = (char *)s;

	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

/*int main()
{
	char	buffer[] = "A L O HH";
	size_t	n = sizeof(buffer);

	ft_bzero(buffer, n);
	for (int i = 0; i < sizeof(buffer); i++)
	{
		printf("%d ", buffer[i]);
	}
	printf("\n");
	printf("buffer as str : %s\n", buffer);
}
*/