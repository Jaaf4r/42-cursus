/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:57:31 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/05 12:52:19 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstln;
	size_t	srcln;
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (0);
	dstln = ft_strlen(dst);
	srcln = ft_strlen(src);
	if (size <= dstln)
		return (size + srcln);
	i = 0;
	j = dstln;
	while (src[i] && j < size - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstln + srcln);
}
