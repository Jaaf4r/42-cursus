#include "ps.h"

static void	swwap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int arr[], int left, int right)
{
	int	pivot = arr[right];
	int	i = left - 1;
	int	j = left;

	while (j < right)
	{
		if (arr[j] < pivot)
		{
			i++;
			swwap(&arr[i], &arr[j]);
		}
		j++;
	}
	swwap(&arr[i + 1], &arr[right]);
	return (i + 1);
}

void	quickSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int part_i = partition(arr, left, right);

		quickSort(arr, left, part_i - 1);
		quickSort(arr, part_i + 1, right);
	}
}
