#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	start = new;
	while (*s1)
		*new++ = *s1++;
	while(*s2)
		*new++ = *s2++;
	*new = '\0';
	return (start);
}

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

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	while (*s)
		*dst++ = *s++;
	dst[size] = '\0';
	return (dst);
}
