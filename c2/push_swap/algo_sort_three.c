/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:24:55 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:24:56 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_one(t_node **stack_a)
{
	sa(stack_a);
	write(1, "sa\n", 3);
}

static void	case_two(t_node **stack_a)
{
	sa(stack_a);
	rra(stack_a);
	write(1, "sa\n", 3);
	write(1, "rra\n", 4);
}

static void	case_three(t_node **stack_a)
{
	ra(stack_a);
	write(1, "ra\n", 3);
}

static void	case_four(t_node **stack_a)
{
	sa(stack_a);
	ra(stack_a);
	write(1, "sa\n", 3);
	write(1, "ra\n", 3);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		case_one(stack_a);
	else if (first > second && second > third)
		case_two(stack_a);
	else if (first > second && second < third && first > third)
		case_three(stack_a);
	else if (first < second && second > third && first < third)
		case_four(stack_a);
	else if (first < second && second > third && first > third)
	{
		rra(stack_a);
		write(1, "rra\n", 4);
	}
}
