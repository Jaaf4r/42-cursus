/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:34:53 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/07 10:45:04 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void print_uppercase(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        printf("%c", ft_toupper(*str));
        str++;
    }
    printf("\n");
}

int main()
{
    t_list *head = ft_lstnew(ft_strdup("hello"));
    t_list *node2 = ft_lstnew(ft_strdup("world"));
    t_list *node3 = ft_lstnew(ft_strdup("linked list"));

    head->next = node2;
    node2->next = node3;

    ft_lstiter(head, print_uppercase);
    ft_lstclear(&head, free);
}*/