#include <stdio.h>

/**
 * Insertion Sort: Insert each element into its correct position in a sorted portion.
 * Complexity: O(n²) worst-case, O(n) best-case.
 * Use Case: Nearly sorted datasets, simplicity.
 */

void	insertion_sort(int arr[], int n)
{
	int	i = 1;

	while (i < n)
	{
		int key = arr[i];
		int	j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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

int main()
{
	int arr[] = {64, 11 , 15, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	print_array(arr, n);

	insertion_sort(arr, n);

	printf("Sorted array: ");
	print_array(arr, n);
}