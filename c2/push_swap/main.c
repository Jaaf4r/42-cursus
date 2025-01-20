#include "ps.h"

int	main(int ac, char **av)
{
	char	**all_val;
	int		i;
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	if (ac < 2)
		return (1);

	all_val = parse_input(av);
	if (!all_val)
		return (1);

	i = 0;
	while (all_val[i])
	{
		ft_lstadd_back(&stack_a, create_node(ft_atoi(all_val[i])));
		i++;
	}
	free_split(all_val);

	if (!is_sorted(stack_a))
	{
		printf("Needs Sorting\n");
		print_stack(stack_a);

		pushNonLisTo_stack_b(&stack_a, &stack_b);

		push_to_a(&stack_a, &stack_b);

		print_stack(stack_a);
		print_stack(stack_b);
		
	}
	else
		printf("Sorted\n");

	free_stack(stack_a);
	return (0);
}
