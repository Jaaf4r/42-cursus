#include "ps.h"

void	sa(t_node **stack_a)
{
	t_node	*first = NULL;
	t_node	*second = NULL;

	if (stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
}

void	sb(t_node **stack_b)
{
	t_node	*first = NULL;
	t_node	*second = NULL;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
	}
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b)
	{
		t_node	*first = *stack_b;
		(*stack_b) = (*stack_b)->next;
		first->next = *stack_a;
		*stack_a = first;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
	{
		t_node	*first = *stack_a;
		*stack_a = (*stack_a)->next;
		first->next = *stack_b;
		*stack_b = first;
	}
}
