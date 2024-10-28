/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:57:22 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/28 12:57:23 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_length(n);
	s = (char *)malloc(len + sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
		
	while (n)
	{
		s[--len] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}

/*int	main()
{
	int		n = -43243;
	char	*s = ft_itoa(n);

	printf("%s\n", s);
}*/