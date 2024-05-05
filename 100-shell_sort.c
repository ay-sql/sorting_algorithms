#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @x: The first int
 * @y: The second int to be swapped
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order.
 * @array: array of integers
 * @size: size of the array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, k;

	if (!array || !size)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			k = i;
			while (k >= gap && array[k - gap] > array[k])
			{
				swap_ints(array + k, array + (k - gap));
				k -= gap;
			}
		}
		print_array(array, size);
	}
}
