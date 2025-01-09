#include "ps.h"

int main(int ac, char **av)
{
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;
	char	**all_val;
	int		i;

	if (ac > 1)
	{
		all_val = parse_input(av);
		if (!all_val)
			return (ft_printf("Error\n"), 1);
		i = 0;
		while (all_val[i])
		{
			t_node	*new_node = create_node(ft_atoi(all_val[i]));
			if (!new_node)
			{
				free_split(all_val);
				free_stack(stack_a);
				return (1);
			}
			ft_lstaddfront(&stack_a, new_node);
			i++;
		}
		free_split(all_val);
		// Test Stack Operations
        ft_printf("Initial stack_a:\n");
        print_stack(stack_a);

		int	*length = 0;
		if (!(is_sorted(stack_a)))
		{
			ft_printf("NEEDS SORTING\n");
			int	lis_length;
			int	*seq = get_lis(stack_a, &lis_length);
			push_nonlis(&stack_a, &stack_b, seq, lis_length);

			push_back_to_stack_a(&stack_a, &stack_b);

			ft_printf("\nstack_a:\n");
			print_stack(stack_a);
			ft_printf("\nstack_b:\n");
			print_stack(stack_b);
		}
		else
			ft_printf("Sorted!\n");


        // sa(&stack_a);
        // ft_printf("After sa (swap a):\n");
        // print_stack(stack_a);

        // pb(&stack_a, &stack_b);
        // ft_printf("After pb (push b):\n");
        // ft_printf("stack_a:\n");
        // print_stack(stack_a);
        // ft_printf("stack_b:\n");
        // print_stack(stack_b);

        // Free stacks
        free_stack(stack_a);
        free_stack(stack_b);
    }
    return (0);
}
