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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d <= s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return ((void *)dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	return (ft_memmove(dest, src, n));
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
	ft_memcpy(dst, s, size);
	dst[size] = '\0';
	return (dst);
}