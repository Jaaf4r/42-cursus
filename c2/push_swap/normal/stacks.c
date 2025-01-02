#include "pushswap.h"

t_pushswap  *ft_lstnew(void *data)
{
	t_pushswap  *node;

	node = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_addfront(t_pushswap **lst, t_pushswap *node)
{
	if (!lst || !node)
		return ;
	node->next = *lst;
	if (*lst)
		(*lst)->prev = node;
	*lst = node;
}

int main()
{
	t_pushswap	*head = NULL;

	for (int i = 0; i < 4; i++)
	{
		int	*val = malloc(sizeof(int));
		if (!val)
			return (1);
		*val = i + 1;
		t_pushswap	*new = ft_lstnew(val);
		ft_addfront(&head, new);
	}

	t_pushswap	*curr = head;
	while (curr)
	{
		printf("%d -> ", *(int *)curr->data);
		curr = curr->next;
	}
	printf("NULL\n");

	curr = head;
	while (curr)
	{
		free(curr->data);
		free(curr);
		curr = curr->next;
	}
	return (0);
}
