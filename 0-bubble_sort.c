#include "sort.h"

/**
 * bubble_sort - sort array in asscending order.
 * @array: array to sort.
 * @size: size of array.
 **/

void bubble_sort(int *array, size_t size)
{
	size_t a, b, swap;

	if (array == NULL && size < 2)
	{
		return;
	}
	a = 0;
	while (a < size - 1)
	{
		b = 0;
		while (b < size - 1)
		{
			if (array[b] > array[b + 1])
			{
				swap = array[b];
				array[b] = array[b + 1];
				array[b + 1] = swap;
				print_array(array, size);
			}
			b++;
		}
		a++;
	}
}
