/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:59:26 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/03 19:31:03 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		l;
	t_list	*current;

	l = 0;
	current = lst;
	while (current)
	{
		l++;
		current = current->next;
	}
	return (l);
}

/*int	main()
{
	t_list *head = NULL;

	t_list *node1 = ft_lstnew("aloo");
	ft_lstadd_front(&head, node1);

	t_list *node2 = ft_lstnew("suiiiiiiii");
	ft_lstadd_front(&head, node2);

	t_list *node3 = ft_lstnew("apah");
	ft_lstadd_front(&head, node3);

	printf("%d\n", ft_lstsize(head));

}*/