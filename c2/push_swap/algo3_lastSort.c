#include "ps.h"

int find_min_pos(t_node *stack_a)
{
	int min_val = INT_MAX;
	int min_pos = 0;
	int pos = 0;
	t_node  *curr = stack_a;

	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

int calculate_best_rot(int stack_size, int min_pos)
{
	int ra_cost = min_pos;
	int rra_cost = stack_size - min_pos;

	if (ra_cost <= rra_cost)
		return (ra_cost);
	else
		return (-rra_cost);
}

void    rotate_stack_a(t_node **stack_a)
{
	int	stack_size = ft_lstsize(*stack_a);
	int	min_pos = find_min_pos(*stack_a);
	int	best_rot = calculate_best_rot(stack_size, min_pos);

	if (best_rot > 0)
	{
		while (best_rot-- > 0)
		{
			ra(stack_a);
			printf("ra\n");
		}
	}
	else
	{
		best_rot = -best_rot;
		while (best_rot-- > 0)
		{
			rra(stack_a);
			printf("rra\n");
		}
	}
}
