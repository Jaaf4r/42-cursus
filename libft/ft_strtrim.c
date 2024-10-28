/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:59:12 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/28 11:55:34 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check_set(s1[start], set))
		start++;
	while (end > start && ft_check_set(s1[end - 1], set))
		end--;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (end - start)
	{
		new[i++] = s1[start++];
	}
	new[i] = '\0';
	return (new);
}

/*int	main()
{
	char	*s1 = "-!!-Hello,!!----!!Worl--!!d-!-!";
	char	*set = "!-";
	char	*res = ft_strtrim(s1, set);

	if (res)
	{
		printf("Trimmed string: '%s'\n", res);
		free(res);
	}
}*/