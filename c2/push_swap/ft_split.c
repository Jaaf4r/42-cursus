/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:44:09 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 10:44:10 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*malloc_words(char *s, char c)
{
	int		i;
	int		c_len;
	char	*word;

	c_len = 0;
	while (s[c_len] && s[c_len] != c)
		c_len++;
	word = malloc(sizeof(char) * (c_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < c_len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_split_helper(char *s, char c, int *i, char **sp)
{
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			sp[*i] = malloc_words(s, c);
			if (!sp[*i])
			{
				while (*i > 0)
					free(sp[--(*i)]);
				free(sp);
				return (NULL);
			}
			(*i)++;
		}
		while (*s && *s != c)
			s++;
	}
	return (sp);
}

char	**ft_split(char *s, char c)
{
	char	**sp;
	int		size;
	int		i;

	size = count_words(s, c);
	sp = malloc(sizeof(char *) * (size + 1));
	if (!sp)
		return (NULL);
	i = 0;
	sp = ft_split_helper(s, c, &i, sp);
	sp[i] = NULL;
	return (sp);
}
