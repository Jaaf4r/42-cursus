/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:30:36 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/04 12:34:01 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	const char	*q;

	if (!str)
		return (NULL);
	q = str;
	while (*q != '\0')
	{
		if (*q == search_str)
			return ((char *)q);
		q++;
	}
	if (search_str == '\0')
		return ((char *)q);
	return (NULL);
}
