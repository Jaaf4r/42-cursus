#include "ps.h"

void	sa(t_node **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		t_node	*first = *stack_a;
		t_node	*second = (*stack_a)->next;

		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
}

void	sb(t_node **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		t_node	*first = *stack_b;
		t_node	*second = (*stack_b)->next;

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
		t_node	*tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a)
	{
		t_node	*tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}
