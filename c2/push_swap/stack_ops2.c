/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:07:50 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 11:07:51 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp = *stack_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
	}
}

void	rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp = *stack_b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
	}
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
