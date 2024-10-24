/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:40:39 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/24 10:30:12 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*q;

	q = (unsigned char *)str;
	while (n > 0)
	{
		*q = (unsigned char)c;
		q++;
		n--;
	}
	return ((void *)str);
}

/*
int	main()
{
	unsigned char	str[] = "Youkoso watashi no soul society!";

	ft_memset(str+8, '>', 7);
	ft_memset(str+17, '.', 5);
	printf("%s\n", str);
}
*/