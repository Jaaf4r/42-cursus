/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:03:49 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/28 23:51:48 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	ft_memmove(d, s, n);
	return ((void *)dest);
}

/*int	main()
{
	char	*src = "alooo";
	char	dst[9];
	char	d[9];

	memcpy(d, src, 9);
	printf("%s\n", d);
	ft_memcpy(dst, src, 9);
	printf("%s\n", dst);
}*/