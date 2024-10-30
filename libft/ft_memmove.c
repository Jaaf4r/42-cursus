/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:31:01 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/30 11:25:00 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	if (src == dest)
// 		return (dest);
// 	d = (unsigned char *)dest;
// 	s = (unsigned char *)src;
// 	if (d > s && d < s + n)
// 	{
// 		while (n--)
// 		{
// 			d[n] = s[n];
// 		}
// 	}
// 	else
// 	{
// 		while (n--)
// 			*d++ = *s++;
// 	}
// 	return ((void *)dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d <= s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return ((void *)dest);
}

/*int	main()
{
	char	buffer[20] = "Hello,world!";
	char	s[20] = "Hello,world!";

	printf("built-in : %p\n", memmove(buffer + 3, buffer + 4, 11));
	printf("mine :     %p\n", ft_memmove(s + 3, s + 4, 11));
	printf("%s\n", buffer);
	printf("%s\n", s);
}*/