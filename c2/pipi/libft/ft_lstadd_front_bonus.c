/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:29:56 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/03 19:29:57 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	t_list *head = NULL;

	t_list *node1 = ft_lstnew("first node");
	ft_lstadd_front(&head, node1);
	
	t_list *node2 = ft_lstnew("2nd node");
	ft_lstadd_front(&head, node2);

	t_list *current = head;
	while (current)
	{
		printf("Node content: %s\n", (char *)current->content);
		current = current->next;
	}
	
	while (head)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}
}*/