#include "ps.h"

int	main(int ac, char **av)
{
	char	**all_val;
	int		i;

	if (ac > 1)
	{
		i = 0;
		all_val = parse_input(av);
		if (!all_val)
			return (printf("Error\n"), 1);
		printf("Parsed values:\n");
        for (i = 0; all_val[i]; i++)
            printf("%s\n", all_val[i]);
        free_split(all_val);
        return (0);
	}
}
