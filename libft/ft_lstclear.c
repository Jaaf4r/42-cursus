/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:28:51 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/31 11:32:59 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

/*void	del(void *content)
{
	free(content);
}

int	main()
{
	t_list	*head = ft_lstnew(ft_strdup("1st node"));
	t_list	*node2 = ft_lstnew(ft_strdup("2nd node"));
	t_list	*node3 = ft_lstnew(ft_strdup("3rd node"));

	head->next = node2;
	node2->next = node3;

	t_list	*curr = head;
	printf("Displaying the list:\n");
	while (curr)
	{
		printf("- %s\n", (char *)curr->content);
		curr = curr->next;
	}

	ft_lstclear(&head, del);

	curr = head;

	if (curr == NULL)
		printf("------------------------\nTamma l clear bi naja7.\n");

}*/