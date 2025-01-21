#include "ps.h"

int	main(int ac, char **av)
{
	char	**all_val;
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;
	long	value;

	stack_a = NULL;
	stack_b = NULL;
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
	if (!is_sorted(stack_a))
	{
		if (is_reversed(stack_a))
		{
			sa(&stack_a);
			write(1, "sa\n", 3);
		}
		pushNonLisTo_stack_b(&stack_a, &stack_b);
		push_to_a(&stack_a, &stack_b);
		rotate_stack_a(&stack_a);
	}
	free_stack(stack_a);
	return (0);
}
