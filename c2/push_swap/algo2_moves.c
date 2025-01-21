#include "ps.h"

int	insert_pos(t_node *stack_a, int value)
{
	t_node	*current = stack_a;
	int		position = 0;
	int		min_pos = 0;
	int		min_value = INT_MAX;
	int		max_value = INT_MIN;

	// Find min and max values and min position in stack_a
	current = stack_a;
	position = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = position;
		}
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
		position++;
	}

	// If value is smaller than min or larger than max,
	// it should go right before the minimum value
	if (value < min_value || value > max_value)
		return (min_pos);

	// Find the correct position between two numbers
	current = stack_a;
	position = 0;
	t_node	*next = current->next;
	
	while (next)
	{
		if (current->value < value && value < next->value)
			return (position + 1);
		current = current->next;
		next = next->next;
		position++;
	}

	// If we haven't found a position yet, check if it fits between the last and first element
	if (stack_a->value > value && current->value < value)
		return (0);
		
	return (position + 1);
}

int	calculate_rot_cost(int stack_size, int index)
{
	if (index <= stack_size / 2)
		return (index);
	return (-(stack_size - index));
}

int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	push_to_a(t_node **stack_a, t_node **stack_b, int *total_moves)
{
	while (*stack_b)
	{
		int		size_a = ft_lstsize(*stack_a);
		int		size_b = ft_lstsize(*stack_b);
		t_node	*curr_b = *stack_b;
		int		best_cost = INT_MAX;
		int		best_a_pos = 0;
		int		best_b_pos = 0;

		int index = 0;
		while (curr_b)
		{
			int pos_in_a = insert_pos(*stack_a, curr_b->value);
			int cost_a = calculate_rot_cost(size_a, pos_in_a);
			int cost_b = calculate_rot_cost(size_b, index);

			int	total_cost;
            if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
                total_cost = max(abs_val(cost_a), abs_val(cost_b));
            else
                total_cost = abs_val(cost_a) + abs_val(cost_b);

			if (total_cost < best_cost)
			{
				best_cost = total_cost;
				best_a_pos = cost_a;
				best_b_pos = cost_b;
			}
			curr_b = curr_b->next;
			index++;
		}

		while (best_a_pos > 0 && best_b_pos > 0)
		{
			rr(stack_a, stack_b);
			best_a_pos--;
			best_b_pos--;
			printf("rr\n");
			(*total_moves)++;
		}
		while (best_a_pos < 0 && best_b_pos < 0)
		{
			rrr(stack_a, stack_b);
			best_a_pos++;
			best_b_pos++;
			printf("rrr\n");
			(*total_moves)++;
		}


		while (best_b_pos > 0)
		{
			rb(stack_b);
			best_b_pos--;
			printf("rb\n");
			(*total_moves)++;
		}
		while (best_b_pos < 0)
		{
			rrb(stack_b);
			best_b_pos++;
			printf("rrb\n");
			(*total_moves)++;
		}

		while (best_a_pos > 0)
		{
			ra(stack_a);
			best_a_pos--;
			printf("ra\n");
			(*total_moves)++;
		}
		while (best_a_pos < 0)
		{
			rra(stack_a);
			best_a_pos++;
			printf("rra\n");
			(*total_moves)++;
		}

		pa(stack_a, stack_b);
		printf("pa\n");
		(*total_moves)++;
	}
}
