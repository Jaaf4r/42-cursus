/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:13:47 by jabouhni          #+#    #+#             */
/*   Updated: 2024/11/04 12:38:44 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*q;
	unsigned int	slen;

	slen = ft_strlen(s);
	if (slen <= start)
	{
		q = malloc(1);
		if (!q)
			return (NULL);
		q[0] = '\0';
		return (q);
	}
	if (len > slen - start)
		len = slen - start;
	q = (char *)malloc(sizeof(char) * (len + 1));
	if (!q)
		return (NULL);
	ft_strlcpy(q, &s[start], len + 1);
	return (q);
}
