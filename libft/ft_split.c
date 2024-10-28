/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:14:16 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/28 11:58:21 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	check_sep(const char *s, char c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return (1);
// 		s++;
// 	}
// 	return (0);
// }

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*malloc_words(const char *s, char c)
{
	int		i;
	int		wordlen;
	char	*word;

	wordlen = 0;
	while (s[wordlen] && s[wordlen] != c)
		wordlen++;
	word = (char *)malloc((wordlen + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < wordlen)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[i] = malloc_words(s, c);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

/*int	main()
{
	char	*s = "baysal raso kbir";
	char	**arr = ft_split(s, 'a');
	int		i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}*/