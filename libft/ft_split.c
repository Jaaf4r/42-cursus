/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:14:16 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/27 22:41:58 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s);
	str = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*str[i])
	{
		ft_strlcat()
	}
}

int	main()
{
	char	*s = "	alo si btata      ";

	printf("%d\n", count_words(s));
}