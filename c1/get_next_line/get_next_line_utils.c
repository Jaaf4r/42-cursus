#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*q;

	if (!s)
		return (NULL);
	q = s;
	while (*q != '\0')
	{
		if (*q == (char)c)
			return ((char *)q);
		q++;
	}
	if (c == 0)
		return ((char *)q);
	return (NULL);
}
