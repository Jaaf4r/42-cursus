#include "push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		last = *stack_a;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		last->next = *stack_a;
		*stack_a = last;
		before_last->next = NULL;
	}
}

void	rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*before_last;

	if (*stack_b && (*stack_b)->next)
	{
		last = *stack_b;
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		last->next = *stack_b;
		*stack_b = last;
		before_last->next = NULL;
	}
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
