#include "ps.h"

void	ra(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		t_node	*first = *stack_a;
		*stack_a = (*stack_a)->next;

		t_node	*last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	rb(t_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		t_node	*first = *stack_b;
		*stack_b = (*stack_b)->next;

		t_node	*last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
