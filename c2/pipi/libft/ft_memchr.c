/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:30:19 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/05 22:03:01 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*q;

	q = (unsigned char *)s;
	while (n--)
	{
		if (*q == (unsigned char)c)
			return ((void *)q);
		q++;
	}
	return (NULL);
}
