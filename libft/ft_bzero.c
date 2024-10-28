/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:58:41 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/28 14:43:24 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

/*
int main()
{
	char	buffer[] = "A L O HH";
	size_t	n = sizeof(buffer);
	bzero(buffer - 2, n-2);
	for (long unsigned i = 0; i < n; i++)
	{
		printf("%d ", buffer[i]);
	}
	printf("\nbuffer as str(built-in) : %s\n", buffer);
	ft_bzero(buffer - 2, n-2);
	for (long unsigned j = 0; j < n; j++)
	{
		printf("%d ", buffer[j]);
	}
	printf("\nbuffer as str(my func) : %s\n", buffer);
}
*/