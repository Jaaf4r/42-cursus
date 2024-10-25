/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:46:52 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 21:53:52 by jabouhni         ###   ########.fr       */
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
    char dest[20];
    const char *source = "Hello, world!";
    size_t copied_length;

    // Normal case
    copied_length = ft_strlcpy(dest, source, sizeof(dest));
    printf("Copied string: '%s', Length of source: %zu\n", dest, copied_length);

    // Test case 1: NULL destination
    dest[0] = '\0';  // Clear dest for clarity
    copied_length = ft_strlcpy(NULL, source, sizeof(dest));
    printf("Copied string: '%s', Length of source: %zu (NULL dst)\n", dest, copied_length);

    // Test case 2: NULL source
    dest[0] = '\0';  // Clear dest for clarity
    copied_length = ft_strlcpy(dest, NULL, sizeof(dest));
    printf("Copied string: '%s', Length of source: %zu (NULL src)\n", dest, copied_length);

    // Test case 3: Both pointers NULL
    dest[0] = '\0';  // Clear dest for clarity
    copied_length = ft_strlcpy(NULL, NULL, sizeof(dest));
    printf("Copied string: '%s', Length of source: %zu (NULL both)\n", dest, copied_length);

    return 0;

	// amjnan case
	char	d[] = "klb";
	char	s[] = "baysal";
	
	printf("%ld\n", ft_strlcpy(d,s,2));
	printf("%s\n", d);
}*/