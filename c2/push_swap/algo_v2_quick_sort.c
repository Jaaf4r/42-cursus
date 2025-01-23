/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_v2_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabouhni <jabouhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:13:52 by jabouhni          #+#    #+#             */
/*   Updated: 2025/01/23 19:21:27 by jabouhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int arr[], int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}

void	quick_sort(int *arr, int left, int right)
{
	int	part_i;

	if (left < right)
	{
		part_i = partition(arr, left, right);
		quick_sort(arr, left, part_i - 1);
		quick_sort(arr, part_i + 1, right);
	}
}
