/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:03:49 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/30 15:32:23 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	return (ft_memmove(dest, src, n));
}

/*int	main()
{
	char	src[50] = "si btata";
	char	dst[50] = "alo ";
	char	d[50] = "alo ";

	memcpy(d + 2, src, 5);
	printf("original : %s", d);
	printf("\n");
	ft_memcpy(dst + 2, src, 5);
	printf("mine : %s", dst);
	printf("\n");
}*/