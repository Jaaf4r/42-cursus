/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:26:13 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/26 17:51:07 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	first = NULL;
	second = NULL;
	if (*stack_a && (*stack_a)->next)
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
	t_node	*first;
	t_node	*second;

	first = NULL;
	second = NULL;
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
	t_node	*first;

	if (*stack_b)
	{
		first = *stack_b;
		(*stack_b) = (*stack_b)->next;
		first->next = *stack_a;
		*stack_a = first;
	}
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*first;

	if (*stack_a)
	{
		first = *stack_a;
		*stack_a = (*stack_a)->next;
		first->next = *stack_b;
		*stack_b = first;
	}
}
