#include "ps.h"

int	main(int ac, char **av)
{
	char	**all_val;
	int		i;
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;

	if (ac > 1)
	{
		all_val = parse_input(av);
		if (!all_val)
			return (printf("Error\n"), 1);

		i = 0;
		while (all_val[i])
		{
			t_node	*new_node = create_node(ft_atoi(all_val[i]));
			if (!new_node)
				return (free_split(all_val), 1);
			ft_lstadd_front(&stack_a, new_node);
			i++;
		}

		if (!is_sorted(stack_a))
		{
			printf("Needs Sorting\n");
			print_stack(stack_a);
			int	*sorted_arr = get_non_lis(stack_a);
			int	len = ft_lstsize(stack_a);
			for (int i = 0; i < len; i++)
			{
				printf("%d ", sorted_arr[i]);
			}
			printf("\n");
			
		}
		else
		{
			printf("Sorted\n");
			print_stack(stack_a);
		}
		


	}
	return (0);
}
