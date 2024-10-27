/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:31:01 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/27 15:46:16 by jabouhni         ###   ########.fr       */
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

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	d = (unsigned char *)dest;
// 	s = (unsigned char *)src;
// 	if (d <= s)
// 	{
// 		while (n--)
// 		{
// 			*d-- = *s--;
// 		}
// 	}
// 	else
// 		*d++ = *s++;
// 	return ((void *)dest);
// }

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	d = (unsigned char *)dest;
// 	s = (unsigned char *)src;
// 	while (n--)
// 		d[n] = s[n];
// 	return ((void *)dest);
// }

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	d = (unsigned char *)dest;
// 	s = (unsigned char *)src;
// 	if (dest <= src)
// 	{
// 		dest = ft_memcpy(dest, src, n);
// 	}
// 	else
// 	{
// 		while (n--)
// 			d[n] = s[n];
// 	}
// 	return ((void *)dest);
// }

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {	
// 	unsigned char	*s1;
// 	unsigned char	*s2;

// 	s1 = (unsigned char *)src;
// 	s2 = (unsigned char *)dst;
// 	if (dst <= src)
// 		dst = ft_memcpy(dst, src, len);
// 	else
// 	{
// 		while (len--)
// 			s2[len] = s1[len];
// 	}
// 	return (dst);
// }

int	main()
{
	char	buffer[] = "Hello,world!";

	printf("%s\n", (unsigned char *)memmove(buffer+5, buffer+2, 4));
	printf("%s\n", (unsigned char *)ft_memmove(buffer+5, buffer+2, 4));
}