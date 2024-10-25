/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:30:19 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 17:37:22 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*q;

	q = (unsigned char *)s;
	while (n > 0)
	{
		if (*q == (unsigned char)c)
			return ((void *)q);
		q++;
		n--;
	}
	return (NULL);
}

/*
int	main()
{
	const char	p[] = "alo si btata!";
	void		*test = memchr(p, 'i', sizeof(p));
	void		*res = ft_memchr(p, 'i', sizeof(p));

	printf("built-in func: [%s]\nmy func: [%s]\n", (char *)test, (char *)res);
}*/