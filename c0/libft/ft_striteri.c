/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:51:52 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/28 22:34:29 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void to_uppercase(unsigned int i, char *c)
{
	i = 0;
    if (c[i] && (c[i] >= 'a' && c[i] <= 'z'))
	{
        c[i] -= 32;
    }
}

int main() {
    char str[] = "hello world";
    ft_striteri(str, to_uppercase);
    printf("%s\n", str);
    return 0;
}*/