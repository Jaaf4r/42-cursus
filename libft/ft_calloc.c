/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:42:21 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 18:25:51 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	char	*arr;

	if (n_elem > SIZE_MAX / size)
		return (NULL);
	arr = (char *)malloc(size * n_elem);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * n_elem);
	return ((void *)arr);
}

int	main()
{
	char	*q = ft_calloc(2000000000, sizeof(char));
	
	int		i = 0;

	while (i < 2000000000)
	{
		printf("%d ", q[i]);
		i++;
	}
	printf("\n");
}