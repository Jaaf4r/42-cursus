/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:46:52 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/26 10:18:38 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcln;
	size_t	i;

	if (!dst || !src)
		return (0);
	srcln = ft_strlen(src);
	if (size == 0)
		return (srcln);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcln);
}

/*int main() {
    char dst[20];
    const char *src = "Hello, world!";
    size_t copied_len;

    // Normal case
    copied_len = ft_strlcpy(dst, src, sizeof(dst));
    printf("Copied str: '%s', srclen: %zu\n", dst, copied_len);

    // Test case 1: NULL destination
    dst[0] = '\0';  // Clear dest for clarity
    copied_len = ft_strlcpy(NULL, src, sizeof(dst));
    printf("Copied str: '%s', srclen: %zu (NULL dst)\n", dst, copied_len);

    // Test case 2: NULL source
    dst[0] = '\0';  // Clear dest for clarity
    copied_len = ft_strlcpy(dst, NULL, sizeof(dst));
    printf("Copied str: '%s', srclen: %zu (NULL src)\n", dst, copied_len);

    // Test case 3: Both pointers NULL
    dst[0] = '\0';  // Clear dst for clarity
    copied_len = ft_strlcpy(NULL, NULL, sizeof(dst));
    printf("Copied str: '%s', srclen: %zu (NULL both)\n", dst, copied_len);

    return 0;

	// amjnan case
	char	d[] = "klb";
	char	s[] = "baysal";
	
	printf("%ld\n", ft_strlcpy(d,s,2));
	printf("%s\n", d);
}*/