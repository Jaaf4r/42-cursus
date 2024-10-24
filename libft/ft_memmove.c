/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:31:01 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/24 09:55:00 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && d < s + n)
	{
		while (n--)
		{
			*d-- = *s--;
		}
	}
	else
		*d++ = *s++;
	return ((void *)dest);
}

/*
int	main()
{
	char	buffer[] = "Hello,world!";

	printf("%s\n", (unsigned char *)memmove(buffer+5, buffer+2, 4));
	printf("%s\n", (unsigned char *)ft_memmove(buffer+5, buffer+2, 4));
}*/