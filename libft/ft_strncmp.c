/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:15:59 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/24 21:22:33 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t  i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n--)
		i++;
	return (s1[i] - s2[i]);
}

/*int main()
{
	char	s1[] = "wash a lhindi";
	char	s2[] = "wash a l3zi";
	int		ret = ft_strncmp(s1,s2,7);
	printf("%d\n", ret);
}*/