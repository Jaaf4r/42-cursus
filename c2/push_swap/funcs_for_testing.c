#include "ps.h"
#include <stdio.h>

void    print_stack(t_node *stack)
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
