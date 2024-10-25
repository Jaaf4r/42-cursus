/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:48:01 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 17:59:14 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	char	*d;

	dst = (d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1)));
	if (!d)
		return (NULL);
	while (*s)
	{
		*d++ = *s++;
	}
	*d = '\0';
	return (dst);
}

/*int	main()
{
	char	*s = "alo hh";
	char	*d = ft_strdup(s);

	printf("%s\n", d);
}*/