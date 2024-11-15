/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:31:15 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/14 21:18:00 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);dgd
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
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
}*/