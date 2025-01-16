#include "ps.h"

char    *ft_strdup(char *s)
{
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void    free_split(char **ss)
{
	char	**start = ss;

	if (!ss)
		return;
	while (*ss)
	{
		free(*ss);
		ss++;
	}
	free(start);
}

static int	ft_space_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoi(char *s)
{
	int		i;
    long	res;
    int		sign;

	res = 0;
	i = 0;
	sign = ft_space_sign(s, &i);
    while (s[i] >= '0' && s[i] <= '9')
    {
        if (res > (LONG_MAX - (s[i] - '0')) / 10)
        {
            if (sign == 1)
                return LONG_MAX;
            else
                return LONG_MIN;
        }
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
