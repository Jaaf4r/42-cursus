/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:01:27 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/31 13:01:28 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*void	*double_content(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)content * 2;
	return (n);
}

void	del(void *content)
{
	free(content);
}

int	main()
{
	t_list *head = ft_lstnew(malloc(sizeof(int)));
    *(int *)head->content = 1;

    t_list *node2 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node2->content = 2;
    head->next = node2;

    t_list *node3 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node3->content = 3;
    node2->next = node3;

    t_list *new_list = ft_lstmap(head, double_content, del);

    t_list *curr = new_list;
    while (curr)
    {
        printf("%d\n", *(int *)curr->content);
        curr = curr->next;
    }

    // Free both lists
    ft_lstclear(&head, del);
    ft_lstclear(&new_list, del);
}*/