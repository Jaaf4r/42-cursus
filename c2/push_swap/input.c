#include "pushswap.h"

int	check_num(char *s)
{
	while (*s)
	{
		if ((*s >= 'A' && *s <= 'Z') 
		|| (*s >= 'a' && *s <= 'z'))
			return (1);
		s++;
	}
	return (0);
}

int	check_dup(char *s)
{
	int		i;
	char	map[256];

	i = 0;
	while (s[i])
	{
		if (map[s[i]] == 1)
			return (1);
		map[s[i]] = 1;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	**vv;

	i = 0;
	j = 0;
	if (ac > 1)
	{
		while (av[++i])
		{
			vv = ft_split(av[i], ' ');
			if (!vv)
				return (1);
			j = 0;
			while (vv[j])
			{
				if (check_num(av[i]) || check_dup(av[1]))
				{
					printf("Error\n");
					return (0);
				}
				j++;
			}
		}
		printf("NOICE\n");
	}
	return (0);
}
