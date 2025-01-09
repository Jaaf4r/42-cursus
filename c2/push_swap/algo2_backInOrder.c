#include "ps.h"

int	find_target_pos(t_node *stack_a, int value)
{
	int	pos = 0;
	t_node	*curr = stack_a;
	t_node	*smol = stack_a;

	if (!curr)
		return (0);
	
	while (curr)
	{
		if (value < curr->value)
			return (pos);
		// if (smol->value > curr->value)
		// 	smol = curr;
		curr = curr->next;
		pos++;
	}
	return (pos);
}

int	get_node_index(t_node *stack, int value)
{
	int	index = 0;
	t_node	*curr = stack;

	while (curr)
	{
		if (curr->value == value)
			return (index);
		index++;
		curr = curr->next;
	}
	return (-1);
}

int	calculate_moves(int stack_size, int index)
{
	if (index <= stack_size / 2)
		return (index);
	return (stack_size - index);
}

void	find_best_move(t_node *stack_a, t_node *stack_b, int *best_value, int *min_moves)
{
	t_node	*curr = stack_b;
	*min_moves = INT_MAX;

	while (curr)
	{
		int	target_pos = find_target_pos(stack_a, curr->value);

		int	b_index = get_node_index(stack_b, curr->value);

		int	stack_a_size = ft_lstsize(stack_a);
		int	stack_b_size = ft_lstsize(stack_b);

		int	a_moves = calculate_moves(stack_a_size, target_pos);
		int	b_moves = calculate_moves(stack_b_size, b_index);

		int	total_moves = a_moves + b_moves;

		ft_printf("value %d: target pos=%d, b_index=%d, a_moves=%d, b_moves=%d, total_moves=%d\n\n"
				, curr->value, target_pos, b_index, a_moves, b_moves, total_moves);

		if (total_moves < *min_moves)
		{
			*min_moves = total_moves;
			*best_value = curr->value;
			ft_printf("New best value found: %d with %d total moves.\n", *best_value, *min_moves);
		}
		curr = curr->next;
	}
	
}


#include <stdio.h>
int	main()
{
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	ft_lstaddfront(&stack_a, create_node(15));
	ft_lstaddfront(&stack_a, create_node(12));
	ft_lstaddfront(&stack_a, create_node(10));
	ft_lstaddfront(&stack_a, create_node(6));
	ft_lstaddfront(&stack_a, create_node(3));


	ft_lstaddfront(&stack_b, create_node(9));
	ft_lstaddfront(&stack_b, create_node(1));
	ft_lstaddfront(&stack_b, create_node(11));
	ft_lstaddfront(&stack_b, create_node(5));

	int best_value;
	int min_moves;

	find_best_move(stack_a, stack_b, &best_value, &min_moves);

	ft_printf("Best value to move: %d with total moves: %d\n", best_value, min_moves);

    return (0);
}

