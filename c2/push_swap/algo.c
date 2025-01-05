#include "ps.h"

int	is_sorted(t_node *stack)
{
	t_node	*curr;

	if (!stack || !stack->next)
		return (1);

	curr = stack;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

t_node	*find_lis(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr;

	curr = *stack_a;
	if (curr)
	{
		while (!(is_sorted(curr)))
			curr = curr->next;
		
	}
}
