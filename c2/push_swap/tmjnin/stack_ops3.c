#include "ai_ps.h"

void	rra(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		t_node	*last = *stack_a;
		t_node	*second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
}

void	rrb(t_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		t_node	*last = *stack_b;
		t_node	*second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
