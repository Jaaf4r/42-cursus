#include "ps.h"

int	is_invalid_num(char *s)
{
	long	res;
	char	*tmp;

	if (!s || !*s)
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	tmp = s;
	if (!*s)
		return (1);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	res = ft_atoi(tmp);
	if (res > INT_MAX || res < INT_MIN)
		return (1);
	return (0);
}

static char	*normlize_num(char *s)
{
	while (*s == '0' && *(s + 1) != '\0')
		s++;
	return (ft_strdup(s));
}

int	is_dup(char **all_val)
{
	int	i;
	int	j;
	char	*norm_i;
	char	*norm_j;

	i = 0;
	while (all_val[i])
	{
		norm_i = normlize_num(all_val[i]);
		if (!norm_i)
			return (1);
		j = i + 1;
		while (all_val[j])
		{
			norm_j = normlize_num(all_val[j]);
			if (!norm_j)
				return (free(norm_i), 1);
			if (ft_strcmp(norm_i, norm_j) == 0)
				return (free(norm_i), free(norm_j), 1);
			free(norm_j);
			j++;
		}
		free(norm_i);
		i++;
	}
	return (0);
}
