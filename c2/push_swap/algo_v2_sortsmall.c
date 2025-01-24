#include "push_swap.h"

static int	find_min(t_node *stack)
{
    int	min;

    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

static int	find_max(t_node *stack)
{
    int	max;

    max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

static void	sort_three(t_node **stack)
{
    int	min;
    int	max;

    min = find_min(*stack);
    max = find_max(*stack);
    if ((*stack)->value == min)
    {
        sa(stack);
        write(1, "sa\n", 3);
        ra(stack);
        write(1, "ra\n", 3);
    }
    else if ((*stack)->next->value == min)
    {
        if ((*stack)->value == max)
        {
            ra(stack);
            write(1, "ra\n", 3);
        }
        else
        {
            sa(stack);
            write(1, "sa\n", 3);
        }
    }
    else
    {
        if ((*stack)->next->value == max)
        {
            rra(stack);
            write(1, "rra\n", 4);
        }
        else
        {
            sa(stack);
            write(1, "sa\n", 3);
            rra(stack);
            write(1, "rra\n", 4);
        }
    }
}

static void	sort_small(t_node **stack_a, t_node **stack_b)
{
    int	size;

    size = ft_lstsize(*stack_a);
    if (size == 2)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
        {
            sa(stack_a);
            write(1, "sa\n", 3);
        }
    }
    else if (size == 3)
        sort_three(stack_a);
    else
        push_nonlis_to_stack_b(stack_a, stack_b);
}

void	small_or_large_to_b(t_node **stack_a, t_node **stack_b)
{
    int	size;

    size = ft_lstsize(*stack_a);
    if (size <= 3)
        sort_small(stack_a, stack_b);
    else
        push_nonlis_to_stack_b(stack_a, stack_b);
}
