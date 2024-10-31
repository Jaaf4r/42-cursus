/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:59:27 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/31 12:59:17 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
}

/*int main()
{
	t_list *head = NULL;

	t_list *node1 = ft_lstnew("salam");
	ft_lstadd_front(&head, node1);

	t_list *node2 = ft_lstnew("ana btata");
	ft_lstadd_front(&head, node2);

	t_list *node3 = ft_lstnew("alooo");
	ft_lstadd_front(&head, node3);

	printf("%s", (char *)ft_lstlast(head)->content);

	t_list *node4 = ft_lstnew("hhh");
	ft_lstadd_back(&head, node4);

	printf("\n%s", (char *)ft_lstlast(head)->content);
}*/