/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:42:21 by jabouhni          #+#    #+#             */
/*   Updated: 2024/10/25 18:44:51 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	char	*arr;

	if (n_elem && n_elem > SIZE_MAX / size)
		return (NULL);
	arr = (char *)malloc(size * n_elem);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * n_elem);
	return ((void *)arr);
}

/*int main() {
    // Test 1 - Zero Elements
    {
        void *ptr1 = ft_calloc(0, sizeof(int));
        void *ptr2 = calloc(0, sizeof(int));

        printf("Test 1 - Zero Elements:\n");
        printf("ft_calloc returned: %s\n", ptr1 == NULL ? "NULL" : "not NULL");
        printf("calloc returned: %s\n", ptr2 == NULL ? "NULL" : "not NULL");
        free(ptr1);
        free(ptr2);
    }

    // Test 2 - Zero Size
    {
        void *ptr1 = ft_calloc(5, 0);
        void *ptr2 = calloc(5, 0);

        printf("Test 2 - Zero Size:\n");
        printf("ft_calloc returned: %s\n", ptr1 == NULL ? "NULL" : "not NULL");
        printf("calloc returned: %s\n", ptr2 == NULL ? "NULL" : "not NULL");
        free(ptr1);
        free(ptr2);
    }

    // Test 3 - Valid Allocation
    {
        char *ptr1 = ft_calloc(5, sizeof(char));
        char *ptr2 = calloc(5, sizeof(char));

        printf("Test 3 - Valid Allocation:\n");
        if (ptr1 && ptr2) {
            printf("Both returned non-NULL\n");
            for (size_t i = 0; i < 5; i++) {
                printf("ptr1[%zu]: %d, ptr2[%zu]: %d\n", i, ptr1[i], i, ptr2[i]);
            }
        } else {
            printf("One or both returned NULL\n");
        }

        free(ptr1);
        free(ptr2);
    }

    // Test 4 - Overflow Handling
    {
        size_t n_elem = SIZE_MAX;
        size_t size = 2;

        void *ptr1 = ft_calloc(n_elem, size);
        void *ptr2 = calloc(n_elem, size);

        printf("Test 4 - Overflow Handling:\n");
        printf("ft_calloc returned: %s\n", ptr1 == NULL ? "NULL" : "not NULL");
        printf("calloc returned: %s\n", ptr2 == NULL ? "NULL" : "not NULL");

        free(ptr1);
        free(ptr2);
    }

    // Test 5 - Large Allocation
    {
        size_t n_elem = 1000000;
        size_t size = sizeof(int);

        void *ptr1 = ft_calloc(n_elem, size);
        void *ptr2 = calloc(n_elem, size);

        printf("Test 5 - Large Allocation:\n");
        if (ptr1 && ptr2) {
            printf("Both allocated memory successfully.\n");
            printf("Memory allocated for both.\n");
        } else {
            printf("One or both returned NULL\n");
        }

        free(ptr1);
        free(ptr2);
    }

    return 0;
}*/