/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:31:01 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/29 11:50:13 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == dest)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s && d < s + n)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return ((void *)dest);
}

/*int	main()
{
	char	buffer[] = "Hello,orld!";
	char	s[] = "Hello,world!";

	printf("built-in : %s\n", (unsigned char *)memmove(buffer, s, 11));
	printf("mine :     %s\n", (unsigned char *)ft_memmove(buffer, s, 11));
}*/