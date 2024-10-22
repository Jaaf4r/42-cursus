/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:30:19 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/22 17:23:21 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*q;
	
	q = (unsigned char *)s;
	while (n >= 0)
	{
		if (*q == (unsigned char)c)
			return (void *(q));
		q++;
		n--;
	}
	return (NULL);
}

/*
int	main()
{
	char	p[] = "alo si btata!";
	char	*test = memchr(p, 'b', sizeof(p));
	char	*res = ft_memchr(p, 'b', sizeof(p));
	printf("built-in func: [%s]\nmy func: [%s]\n", test, res);
}*/