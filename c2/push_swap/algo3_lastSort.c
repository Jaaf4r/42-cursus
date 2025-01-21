#include "push_swap.h"

void	rotate_stack_a(t_node **stack_a)
{
	t_node	*curr;
	int		smallest_pos;
	int		smallest_value;
	int		index;
	int		size;
	int		cost;

	curr = *stack_a;
	smallest_pos = 0;
	index = 0;
	smallest_value = curr->value;
	size = ft_lstsize(*stack_a);
	while (curr)
	{
		if (curr->value < smallest_value)
		{
			smallest_value = curr->value;
			smallest_pos = index;
		}
		curr = curr->next;
		index++;
	}
	cost = calculate_rot_cost(size, smallest_pos);
	while (cost > 0)
	{
		ra(stack_a);
		cost--;
		write(1, "ra\n", 3);
	}
	while (cost < 0)
	{
		rra(stack_a);
		cost++;
		write(1, "rra\n", 4);
	}
}
