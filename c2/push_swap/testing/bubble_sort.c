#include <stdio.h>

/**
 * Bubble Sort: Compare adjacent elements and swap if needed.
 * Complexity: O(n²)
 * Use Case: Small datasets, learning stability and in-place operations.
 */

void	bubble_sort(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		int	j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				int	tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	print_array(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int	main()
{
	int arr[] = {64, 34, 25, 12, 22, 90, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	print_array(arr, n);

	bubble_sort(arr, n);

	printf("Sorted array: ");
	print_array(arr, n);

	return (0);
}
