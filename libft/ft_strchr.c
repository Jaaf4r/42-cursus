/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:30:36 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/05 16:06:01 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*q;

	if (!s)
		return (NULL);
	q = s;
	while (*q != '\0')
	{
		if (*q == (char)c)
			return ((char *)q);
		q++;
	}
	if (c == 0)
		return ((char *)q);
	return (NULL);
}
