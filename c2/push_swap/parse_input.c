#include "ps.h"

char    **parse_input(char **av)
{
	int		i;
	int		j;
	int		total_count;
	char	**vessel;
	char	**all_val;
	int		all_i;

	i = 0;
	total_count = 0;
	while (av[++i])
		total_count += count_words(av[i], ' ');
	all_val = malloc(sizeof(char *) * (total_count + 1));
	if (!all_val)
		return (NULL);
	i = 0;
	all_i = 0;
	while (av[++i])
	{
		vessel = ft_split(av[i], ' ');
		if (!vessel)
			return (free(all_val), NULL);
		j = 0;
		while (vessel[j])
		{
			all_val[all_i] = ft_strdup(vessel[j]);
			if (!all_val[all_i])
				return (free_split(vessel), free_split(all_val), NULL);
			j++;
			all_i++;
		}
		free_split(vessel);
	}
	all_val[all_i] = NULL;
	all_i = 0;
	while (all_val[all_i])
	{
		if (is_invalid_num(all_val[all_i]))
			return (printf("Error\n"), free_split(all_val), NULL);
		all_i++;
	}
	if (is_dup(all_val))
		return (printf("Error\n"), free_split(all_val), NULL);
	return (all_val);
}
