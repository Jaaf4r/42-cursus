#include "pushswap.h"

int	is_invalid_num(char *s)
{
	char	*endptr;
	long	result;

	errno = 0;
	if (!s || *s == '\0' || (isspace(*s) || (!isdigit(*s) && *s != '-' && *s != '+')))
        return (1);
    result = strtol(s, &endptr, 10);
    if (*endptr != '\0' || errno == ERANGE || result > INT_MAX || result < INT_MIN)
		return (1);
	return (0);
}

char	*normalize_num(const char *s)
{
	while (*s == '0' && *(s + 1) != '\0')
		s++;
	return (ft_strdup(s));
}

int	check_dup(char **v)
{
	int		i;
	int		j;
	char	*normalized_i;
	char	*normalized_j;

	i = 0;
	while (v[i])
	{
		normalized_i = normalize_num(v[i]);
		if (!normalized_i)
			return (1);
		j = i + 1;
		while (v[j])
		{
			normalized_j = normalize_num(v[j]);
			if (!normalized_j)
				return (free(normalized_i), 1);
			if (strcmp(normalized_i, normalized_j) == 0)
				return (free(normalized_i), free(normalized_j), 1);
			free(normalized_j);
			j++;
		}
		free(normalized_i);
		i++;
	}
	return (0);
}

void	free_split(char **v)
{
	int	i;
	if (!v)
        return;
	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**vv;
	char	**all_val;
	int		total_count;
	int		all_i;

	i = 0;
	j = 0;
	total_count = 0;
	if (ac > 1)
	{
		// counting the splits
		while (av[++i])
		{
			vv = ft_split(av[i], ' ');
			if (!vv)
				return (1);
			j = 0;
			while (vv[j])
			{
				total_count++;
				j++;
			}
			free_split(vv);
		}
		// copying the splits to a new double arr
		all_val = (char **)malloc(sizeof(char *) * (total_count + 1));
		if (!all_val)
			return (1);
		i = 0;
		all_i = 0;
		while (av[++i])
		{
			vv = ft_split(av[i], ' ');
			if (!vv)
			{
				free_split(all_val);
				return (1);
			}
			j = 0;
			while (vv[j])
			{
				all_val[all_i] = ft_strdup(vv[j]);
				if (!all_val[all_i])
				{
					free_split(vv);
					free_split(all_val);
					return (1);
				}
				all_i++;
				j++;
			}
			free_split(vv);
		}
		all_val[all_i] = NULL;
		// checking for errors
		i = 0;
		while (all_val[i])
		{
			if (is_invalid_num(all_val[i]))
			{
				printf("Error\n");
				free_split(all_val);
				return (0);
			}
			i++;
		}
		if (check_dup(all_val))
		{
			printf("Error\n");
			free_split(all_val);
			return (0);
		}
		free_split(all_val);
		printf("NOICE\n");
	}
	return (0);
}
