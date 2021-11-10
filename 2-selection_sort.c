#include "sort.h"

/**
 * selection_sort - Selection sort
 * @array: Array
 * @size: Size
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	int tmp;
	size_t j = 0;
	int *vodka = NULL;
	int *ron = NULL;
	int min_idx = 0;
	int swap;

	if (size <= 1)
		return;

	for (i = 0 ; i < size ; i++)
	{
		swap = 0;
		min_idx = i;
		vodka = &array[i];
		for (j = i ; j < size ; j++)
		{
			ron = &array[j];
			if (*ron < *vodka)
			{
				min_idx = j;
				vodka = &array[min_idx];
				swap = 1;
			}
		}
		if (swap == 1)
		{
			vodka = &array[i];
			ron = &array[min_idx];
			tmp = *vodka;
			*vodka = *ron;
			*ron = tmp;
			print_array(array, size);

		}
	}
}

