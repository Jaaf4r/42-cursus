/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:30:19 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/05 17:06:59 by jabouhni         ###   ########.fr       */
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

// int	main()
// {
// 	const char	p[] = "hello, world!";
// 	char	*test = (void *)memchr(p, 's', 14);
// 	char	*res = (void *)ft_memchr(p, 's', 14);

// 	printf("built-in func: [%s]\nmy func: [%s]\n", test, res);
// }