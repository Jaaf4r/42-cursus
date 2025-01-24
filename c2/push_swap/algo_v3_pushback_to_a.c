/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v3_pushback_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:25:10 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/24 22:25:21 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	best_costs(t_node *stack_a, t_node *stack_b, t_calc *calc)
{
	calc->pos_in_a = insert_pos(stack_a, stack_b->value);
	calc->cost_a = calculate_rot_cost(calc->size_a, calc->pos_in_a);
	calc->cost_b = calculate_rot_cost(calc->size_b, calc->index);
	if ((calc->cost_a > 0 && calc->cost_b > 0)
		|| (calc->cost_a < 0 && calc->cost_b < 0))
		calc->total_cost = max(abs_val(calc->cost_a),
				abs_val(calc->cost_b));
	else
		calc->total_cost = abs_val(calc->cost_a) + abs_val(calc->cost_b);
	if (calc->total_cost < calc->best_cost)
	{
		calc->best_cost = calc->total_cost;
		calc->best_a_pos = calc->cost_a;
		calc->best_b_pos = calc->cost_b;
	}
}

static void	double_ops(t_node **stack_a, t_node **stack_b, t_calc *calc)
{
	while (calc->best_a_pos > 0 && calc->best_b_pos > 0)
	{
		rr(stack_a, stack_b);
		calc->best_a_pos--;
		calc->best_b_pos--;
		write(1, "rr\n", 3);
	}
	while (calc->best_a_pos < 0 && calc->best_b_pos < 0)
	{
		rrr(stack_a, stack_b);
		calc->best_a_pos++;
		calc->best_b_pos++;
		write(1, "rrr\n", 4);
	}
}

static void	single_ops(t_node **stack_a, t_node **stack_b, t_calc *calc)
{
	while (calc->best_b_pos > 0)
	{
		rb(stack_b);
		calc->best_b_pos--;
		write(1, "rb\n", 3);
	}
	while (calc->best_b_pos < 0)
	{
		rrb(stack_b);
		calc->best_b_pos++;
		write(1, "rrb\n", 4);
	}
	while (calc->best_a_pos > 0)
	{
		ra(stack_a);
		calc->best_a_pos--;
		write(1, "ra\n", 3);
	}
	while (calc->best_a_pos < 0)
	{
		rra(stack_a);
		calc->best_a_pos++;
		write(1, "rra\n", 4);
	}
}

static void	all_ops(t_node **stack_a, t_node **stack_b, t_calc *calc)
{
	double_ops(stack_a, stack_b, calc);
	single_ops(stack_a, stack_b, calc);
	pa(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_to_a(t_node **stack_a, t_node **stack_b)
{
	t_calc	*calc;
	t_node	*tmp_b;

	calc = malloc(sizeof(t_calc));
	if (!calc)
		return ;
	while (*stack_b)
	{
		tmp_b = *stack_b;
		calc->size_a = ft_lstsize(*stack_a);
		calc->size_b = ft_lstsize(*stack_b);
		calc->best_cost = INT_MAX;
		calc->best_a_pos = 0;
		calc->best_b_pos = 0;
		calc->index = 0;
		while (tmp_b)
		{
			best_costs(*stack_a, tmp_b, calc);
			tmp_b = tmp_b->next;
			calc->index++;
		}
		all_ops(stack_a, stack_b, calc);
	}
	free(calc);
}
