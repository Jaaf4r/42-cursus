/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:57:31 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/24 12:31:41 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstln;
	size_t	srcln;
	size_t	i;

	dstln = ft_strlen(dst);
	srcln = ft_strlen(src);
	if (size <= dstln)
		return (size + srcln);
	i = 0;
	while (src[i] && (dstln + i) < size - 1)
	{
		dst[dstln + i] = src[i];
		i++;
	}
	dst[dstln + i] = '\0';
	return (dstln + srcln);
}

/*int main()
{
	char dst[] = "This is ";
	char src[] = "a potentially long string";

	size_t ret = ft_strlcat(dst, src, 15);
	printf("whole thing : <%s>\n", dst);
	printf("value returned : [%ld]\n", ret);
}*/