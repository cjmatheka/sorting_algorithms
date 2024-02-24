#include "sort.h"

/**
 * bubble_sort - sorts an array of items using bubble sorts
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, temp;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			/* swap elements and print after each pass */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		/* If no two elements were swapped in the inner loop, array is sorted */
		if (swapped == 0)
			break;
	}
}