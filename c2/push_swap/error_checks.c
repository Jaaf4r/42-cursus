#include "ps.h"

int	is_invalid_num(char *s)
{
	long	res;
	char	*tmp;
	char	*normalized;

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
	normalized = normlize_num(tmp);
	if (!normalized)
		return (1);
	ft_atoi(normalized, &res);
	if (res > INT_MAX || res < INT_MIN)
		return (1);
	return (0);
}

char	*normlize_num(char *s)
{
	while (*s == '0' && *(s + 1) != '\0')
		s++;
	return (ft_strdup(s));
}

int	is_dup(char **all_val)
{
	int		i;
	int		j;
	char	*norm_i;

	i = 0;
	while (all_val[i])
	{
		norm_i = normlize_num(all_val[i]);
		if (!norm_i)
			return (1);
		all_val[i] = norm_i;
		norm_i = NULL;
		free(norm_i);
		i++;
	}
	i = 0;
	while (all_val[i])
	{
		j = i + 1;
		while (all_val[j])
		{
			if (ft_strcmp(all_val[i], all_val[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
