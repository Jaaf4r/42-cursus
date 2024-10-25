/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:13:47 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 22:33:54 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *q;

    q = (char *)malloc(sizeof(char) * (len + 1));
    if (!q)
        return (NULL);
    ft_strlcpy(q, &s[start], len);
    return (q);
}

/*int main()
{
    char    *s = "jaafar";
    char    *q = ft_substr(s, 2, 3);

    printf("%s\n", q);
}*/