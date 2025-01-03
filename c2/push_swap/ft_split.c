#include "ps.h"

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

static char	**ft_split_helper(char const *s, char c, char **arr, int *i)
{
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[*i] = malloc_words(s, c);
			if (!arr[*i])
			{
				while (*i > 0)
					free(arr[--(*i)]);
				free(arr);
				return (NULL);
			}
			(*i)++;
		}
		while (*s && *s != c)
			s++;
	}
	return (arr);
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
	arr = ft_split_helper(s, c, arr, &i);
	arr[i] = NULL;
	return (arr);
}
