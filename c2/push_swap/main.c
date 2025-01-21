#include "ps.h"

int	main(int ac, char **av)
{
	char	**all_val;
	int		i;
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;
	long	value;

	if (ac < 2)
		return (1);

	all_val = parse_input(av);
	if (!all_val)
		return (1);

	i = 0;
	while (all_val[i])
	{
		if (!ft_atoi(all_val[i], &value))
			return (free_split(all_val), free_stack(stack_a), 1);
		ft_lstadd_back(&stack_a, create_node(value));
		i++;
	}
	free_split(all_val);

	int	total_moves = 0;
	if (!is_sorted(stack_a))
	{
		if (is_reversed(stack_a))
		{
			sa(&stack_a);
			printf("sa\n");
			total_moves++;
		}
		printf("Needs Sorting\n");
		print_stack(stack_a);

		pushNonLisTo_stack_b(&stack_a, &stack_b, &total_moves);

		push_to_a(&stack_a, &stack_b, &total_moves);

		// print_stack(stack_a);
		// print_stack(stack_b);

		// printf("THE END\n\n\n");
		rotate_stack_a(&stack_a, &total_moves);
		printf("stack_a:\n");
		print_stack(stack_a);
		printf("Total number of moves is: %d\n", total_moves);
		if (is_sorted(stack_a))
		{
			printf("******************\n*");
			printf("    VICTORY     *\n");
			printf("******************\n");
		}

	}
	else
	{
		printf("Sorted\n");
		printf("Total number of moves is: %d\n", total_moves);
	}

	free_stack(stack_a);
	return (0);
}
