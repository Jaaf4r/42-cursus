/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:57:31 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/27 10:50:09 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstln;
	size_t	srcln;
	size_t	i;
	size_t	j;

	dstln = ft_strlen(dst);
	srcln = ft_strlen(src);
	if (size <= dstln)
		return (size + srcln);
	i = 0;
	j = dstln;
	while (src[i] && j < size - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstln + srcln);
}

size_t  adahab_strlcat(char *dst, const char *src, size_t size)
{
        size_t sln = 0;
        size_t dln = 0;
        size_t i = 0;
        size_t k = 0;
        while(src[sln])
                sln++;
        while(dst[dln])
                dln++;
        if(size <= dln)
                return sln + size;
        k = dln;
        while(src[i] && i < size - 1)
        {
                dst[k] = src[i];
                i++;
                k++;
        }

        dst[k] = '\0';
        return sln + dln;
}

size_t	t_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

int main()
{
	// char dst[15] = "12345";
	// char src[4] = "abcd";
	// size_t ret = ft_strlcat(dst, src, 15);
	// printf("str dyali : <%s>\n", dst);
	// printf("value dyali : [%ld]\n", ret);
	// printf("---------------------------------\n");
	// char m3mr[15] = "12345";
	// char koufitir[4] = "abcd";
	// size_t hh = adahab_strlcat(m3mr, koufitir, 15);
	// printf("adahab dst : <%s>\n", m3mr);
	// printf("value adahab : [%ld]\n", hh);
	// printf("---------------------------------\n");
	// char d[15] = "12345";
	// char s[4] = "abcd";
	// size_t x = t_strlcat(d, s, 15);
	// printf("original : <%s>\n", d);
	// printf("value original : [%ld]\n", x);


	// testcase 1: When size is large enough to hold both dst and src (+ '\0')
	// char dst[20] = "Hello";
	// const char *src = " World";
	// size_t size = 20;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "Hello World"
	// // result = 11 (length of "Hello" + length of " World")
	// printf("dst = %s\nresult = %ld", dst, result);

	/*--------------------------------------------------------------*/

	// // testcase 2: When size is exactly the combined length of dst and src + '\0'
	// char dst[12] = "Hello";
	// const char *src = " World";
	// size_t size = 12;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "Hello World"
	// // result = 11
	// printf("dst = %s\nresult = %ld", dst, result);

	// /*--------------------------------------------------------------*/

	// // testcase 3: When size allows only part of src to be copied into dst
	// char dst[10] = "Hello";
	// const char *src = " World";
	// size_t size = 10;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "Hello Wor" (only part of " World" fits)
	// // result = 11 (length it *would* have been with enough space)
	// printf("dst = %s\nresult = %ld", dst, result);

	// /*--------------------------------------------------------------*/

	// // testcase 4: When size only has room for dst and no characters from src
	// char dst[6] = "Hello";
	// const char *src = " World";
	// size_t size = 6;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "Hello" (unchanged)
	// // result = 11 (length it *would* have been with enough space)
	// printf("dst = %s\nresult = %ld", dst, result);

	// /*--------------------------------------------------------------*/

	// // testcase 5: When size is smaller than dstln, meaning strlcat will do nothing
	char dst[6] = "Hello";
	const char *src = " World";
	size_t size = 3;
	size_t result = ft_strlcat(dst, src, size);
	size_t x = strlcat(dst, src, size);

	// Expected:
	// dst = "Hello" (unchanged)
	// result = 11 (total length it would be with enough space)
	printf("dst = %s\nresult = %ld", dst, result);
	printf("dst = %s\nresult = %ld", dst, x);
	// /*--------------------------------------------------------------*/

	// // testcase 6: When dst starts as an empty string
	// char dst[20] = "";
	// const char *src = "Hello World";
	// size_t size = 20;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "Hello World"
	// // result = 11 (length of "Hello World")
	// printf("dst = %s\nresult = %ld", dst, result);

	// /*--------------------------------------------------------------*/

	// // testcase 7: When src is empty, dst should remain unchanged, 
	// //             and the result should be dstln
	// char dst[20] = "Hello";
	// const char *src = "";
	// size_t size = 20;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "Hello" (unchanged)
	// // result = 5 (length of "Hello")
	// printf("dst = %s\nresult = %ld", dst, result);

	// /*--------------------------------------------------------------*/

	// // testcase 8: Both dst and src are empty strings; 
	// //             result should be 0 and dst unchanged
	// char dst[20] = "";
	// const char *src = "";
	// size_t size = 20;
	// size_t result = ft_strlcat(dst, src, size);

	// // Expected:
	// // dst = "" (unchanged)
	// // result = 0 (length of empty string)
	// printf("dst = %s\nresult = %ld", dst, result);

}