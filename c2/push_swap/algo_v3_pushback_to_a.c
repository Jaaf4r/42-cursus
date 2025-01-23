#include "push_swap.h"

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
			write(1, "rr\n", 3);
		}
		while (best_a_pos < 0 && best_b_pos < 0)
		{
			rrr(stack_a, stack_b);
			best_a_pos++;
			best_b_pos++;
			write(1, "rrr\n", 4);
		}


		while (best_b_pos > 0)
		{
			rb(stack_b);
			best_b_pos--;
			write(1, "rb\n", 3);
		}
		while (best_b_pos < 0)
		{
			rrb(stack_b);
			best_b_pos++;
			write(1, "rrb\n", 4);
		}

		while (best_a_pos > 0)
		{
			ra(stack_a);
			best_a_pos--;
			write(1, "ra\n", 3);
		}
		while (best_a_pos < 0)
		{
			rra(stack_a);
			best_a_pos++;
			write(1, "rra\n", 4);
		}

		pa(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
}
