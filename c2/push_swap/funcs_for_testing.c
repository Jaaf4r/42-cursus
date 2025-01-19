#include "ps.h"

void    print_stack(t_node *stack)
{
    if (stack)
    {
        while (stack->next)
        {
            printf("%d -> ", stack->value);
            stack = stack->next;
        }
        printf("%d .\n", stack->value);
    }
}
