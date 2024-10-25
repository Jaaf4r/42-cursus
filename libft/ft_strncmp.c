/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:15:59 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 17:46:25 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

/*int main()
{
	char	s1[] = "wasa a lhindi";
	char	s2[] = "wash a l3zi";

	printf("%d\n", ft_strncmp(s1,s2,3));
	printf("%d\n", strncmp(s1,s2,3));
}*/