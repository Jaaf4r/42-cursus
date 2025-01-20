#include "ps.h"

int	insert_pos(t_node *stack_a, int value)
{
	int		pos = 0;
	t_node	*curr = stack_a;

	if (value < stack_a->value)
		return (0);

	while (curr->next)
	{
		if (curr->value < value && curr->next->value > value)
			break;
		curr = curr->next;
		pos++;
	}

	if (curr->next == NULL && value > curr->value)
		return (pos + 1);

	return (pos + 1);
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

void	push_to_a(t_node **stack_a, t_node **stack_b)
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
			int total_cost = abs_val(cost_a) + abs_val(cost_b);

			if (total_cost < best_cost)
			{
				best_cost = total_cost;
				best_a_pos = cost_a;
				best_b_pos = cost_b;
			}
			curr_b = curr_b->next;
			index++;
		}

		printf("before starting:\n");
		print_stack(*stack_a);
		print_stack(*stack_b);
		printf("best a position : %d\n", best_a_pos);
		printf("best b position : %d\n", best_b_pos);
		printf("after\n");


		while (best_a_pos > 0 && best_b_pos > 0)
		{
			rr(stack_a, stack_b);
			best_a_pos--;
			best_b_pos--;
			printf("rr\n");
		}
		while (best_a_pos < 0 && best_b_pos < 0)
		{
			rrr(stack_a, stack_b);
			best_a_pos++;
			best_b_pos++;
			printf("rrr\n");
		}


		while (best_b_pos > 0)
		{
			rb(stack_b);
			best_b_pos--;
			printf("rb\n");
		}
		while (best_b_pos < 0)
		{
			rrb(stack_b);
			best_b_pos++;
			printf("rrb\n");
		}

		while (best_a_pos > 0)
		{
			ra(stack_a);
			best_a_pos--;
			printf("ra\n");
		}
		while (best_a_pos < 0)
		{
			rra(stack_a);
			best_a_pos++;
			printf("rra\n");
		}

		pa(stack_a, stack_b);
		printf("pa\n");
	}
}
