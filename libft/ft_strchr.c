/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:30:36 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 21:16:01 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	const char	*q;

	q = str;
	while (*q)
	{
		if (*q == search_str)
			return ((char *)q);
		q++;
	}
	return (NULL);
}

/*int main ()
{
	const char	str[] = "alo si btata";
	const char	ch = 'z';

	char	*ret = strchr(str, ch);
	char	*x = ft_strchr(str, ch);
	printf("- CHARACTER is |%c|\n- Built-in func output: |%s|\n", ch, ret);
	printf("- My func output: |%s|\n", x);
}*/