#include "sort.h"

/**
 * partition - Partition
 * @A: Array
 * @start: start array
 * @end: End array
 * @size: Size
 *
 * Return: Partition
 */
int partition(int *A, int start, int end, size_t size)
{
	int *pivot = &A[end];
	int part_idx = start - 1;
	int i;
	int tmp;
	int *ptr1 = NULL;
	int *ptr2 = NULL;

	for (i = start ; i <= end - 1 ; i++)
	{
		ptr1 = &A[i];
		if (*ptr1 < *pivot)
		{
			part_idx++;
			ptr2 = &A[part_idx];
			if (*ptr2 != *ptr1)
			{
				tmp = *ptr1;
				*ptr1 = *ptr2;
				*ptr2 = tmp;
				print_array(A, size);
			}
		}
	}
	if (A[part_idx + 1] != A[end])
	{
		ptr2 = &A[part_idx + 1];
		tmp = *ptr2;
		*ptr2  = *pivot;
		*pivot = tmp;
		print_array(A, size);

	}
	return (part_idx + 1);
}

/**
 * quick - Quick
 * @array: Array
 * @start: start array
 * @end: End array
 * @size: Size
 *
 * Return: Nothing
 */
void quick(int *array, int start, int end, size_t size)
{

	int part_idx;

	if (start >= end)
		return;

	part_idx = partition(array, start, end, size);
	quick(array, start, part_idx - 1, size);
	quick(array, part_idx + 1, end, size);
}

/**
 * quick_sort - Quick sort
 * @array: Array
 * @size: Size
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quick(array, 0, size - 1, size);
}

