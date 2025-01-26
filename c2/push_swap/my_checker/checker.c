/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:54:13 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/26 10:54:14 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_linux.h"

static t_node	*valid_stack(char **av)
{
	char	**all_val;
	int		i;
	long	value;
	t_node	*stack_a;

	all_val = parse_input(av);
	if (!all_val)
	{
		write(2, "Error\n", 6);
		return (free_all(all_val), NULL);
	}
	stack_a = NULL;
	i = 0;
	while (all_val[i])
	{
		if (!ft_atoi(all_val[i], &value))
			return (free_all(all_val), NULL);
		ft_lstadd_back(&stack_a, create_node(value));
		i++;
	}
	free_all(all_val);
	return (stack_a);
}

static int	which_operation(t_node **stack_a, t_node **stack_b, char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(operation, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*operation;

	if (ac < 2)
		return (1);
	stack_a = valid_stack(av);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	operation = get_next_line(0);
	while (operation)
	{
		if (which_operation(&stack_a, &stack_b, operation) == 0)
			return (free(operation), write(2, "Error\n", 6), 1);
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted(stack_a) && !ft_lstsize(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(stack_a), 0);
}
