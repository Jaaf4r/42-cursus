/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:10:09 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/07 10:12:55 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void	del(void *content)
{
	free(content);
}

int	main()
{
	t_list	*node = ft_lstnew(ft_strdup("wash a si btata"));

	printf("%s\n", (char *)node->content);

	ft_lstdelone(node, del);

	printf("%s\n", (char *)node->content);
}*/