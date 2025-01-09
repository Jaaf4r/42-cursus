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

void	best_move(t_node *stack_a, t_node *stack_b, int *best_value, int *min_moves)
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

		
	}
	
}


#include <stdio.h>
int main()
{
    t_node	*stack_a = NULL;

	ft_lstaddfront(&stack_a, create_node(10));
	ft_lstaddfront(&stack_a, create_node(7));
	ft_lstaddfront(&stack_a, create_node(5));
	ft_lstaddfront(&stack_a, create_node(3));
	ft_lstaddfront(&stack_a, create_node(2));

    int	test_values[] = {1, 4, 6, 8, 11};
    int	num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++)
	{
		int pos = find_target_pos(stack_a, test_values[i]);
		printf("Value %d should be inserted at position %d in stack_a.\n", test_values[i], pos);
	}



	t_node	*stack_b = NULL;

	ft_lstaddfront(&stack_b, create_node(4));
	ft_lstaddfront(&stack_b, create_node(5));
	ft_lstaddfront(&stack_b, create_node(6));

	int stb_values[] = {4, 5, 6, 7};
    int ntests = sizeof(stb_values) / sizeof(stb_values[0]);

    for (int i = 0; i < ntests; i++)
	{
        int idx = get_node_index(stack_b, stb_values[i]);
        if (idx != -1)
            printf("Value %d is at index %d in stack_b.\n", stb_values[i], idx);
        else
            printf("Value %d not found in stack_b.\n", stb_values[i]);
    }


	int stack_size = 5;

    int test_indices[] = {0, 1, 2, 3, 4};
    int n_tests = sizeof(test_indices) / sizeof(test_indices[0]);

    for (int i = 0; i < n_tests; i++)
	{
        int moves = calculate_moves(stack_size, test_indices[i]);
        printf("Index %d in a stack of size %d requires %d moves.\n", test_indices[i], stack_size, moves);
    }





    return 0;
}
