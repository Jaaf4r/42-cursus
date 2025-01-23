/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:15:25 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 22:16:19 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*valid_stack(char **av)
{
	char	**all_val;
	int		i;
	long	value;
	t_node	*stack_a;

	all_val = parse_input(av);
	if (!all_val)
		return (free_all(all_val), NULL);
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

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = valid_stack(av);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	if (!is_sorted(stack_a))
	{
		if (is_reversed(stack_a))
		{
			sa(&stack_a);
			write(1, "sa\n", 3);
		}
		push_nonlis_to_stack_b(&stack_a, &stack_b);
		push_to_a(&stack_a, &stack_b);
		rotate_stack_a(&stack_a);
	}
	free_stack(stack_a);
	return (0);
}
