/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_for_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:06:06 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 22:16:17 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_node *stack)
{
	if (stack)
	{
		printf("==");
		while (stack->next)
		{
			printf("%d -> ", stack->value);
			stack = stack->next;
		}
		printf("%d .\n", stack->value);
	}
}
