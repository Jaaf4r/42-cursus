/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:40:39 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/03 19:11:11 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*q;

	q = str;
	while (n--)
	{
		*q++ = (unsigned char)c;
	}
	return ((void *)str);
}

/*int	main()
{
	// char	str[] = "Youkoso watashi no soul society!";
	// char	qqq[] = "Youkoso watashi no soul society!";

	// memset(qqq, 255, 1);
	// ft_memset(str, -1, 1);

	// printf("%s\n", qqq);
	// printf("%s\n", str);

	int	a[] = {1,2,4,5,6,34};

	ft_memset(a, 2, 8);
	
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    	printf("%d ", a[i]);

}*/