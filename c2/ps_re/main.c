#include "ps.h"

int	main(int ac, char **av)
{
	char	**all_val;
	int		i;
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	if (ac > 1)
	{
		all_val = parse_input(av);
		if (!all_val)
			return (printf("Error\n"), 1);

		i = 0;
		while (all_val[i])
		{
			t_node	*new_node = create_node(ft_atoi(all_val[i]));
			if (!new_node)
				return (free_split(all_val), 1);
			ft_lstadd_front(&stack_a, new_node);
			i++;
		}
		printf("Initial values of Stack A:\n");
		print_stack(stack_a);

		pb(&stack_a, &stack_b);

		rrr(&stack_a, &stack_b);
		printf("after Stack OPERATION:\n");
		print_stack(stack_a);
		print_stack(stack_b);


	}
	return (0);
}
