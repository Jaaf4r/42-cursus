/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:46:52 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/24 21:15:52 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcln;
	size_t	i;

	srcln = ft_strlen(src);
	if (!dst || !src)
		return (0);
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
    char dst[10] = "Hello";  // Existing content in the destination buffer
    char src[] = "World!";
    
    size_t ret = ft_strlcpy(dst, src, ft_strlen(dst));
    
    printf("New dst: <%s>\n", dst);         // Output: <World!>
    printf("Returned: [%ld]\n", ret);       // Output: Length of src, which is 6
}*/