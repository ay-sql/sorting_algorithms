#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_elements(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i, j;
    int *min;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;
        for (j = i + 1; j < size; j++)
            min = (array[j] < *min) ? (array + j) : min;

        if ((array + i) != min)
        {
            swap_elements(array + i, min);
            print_array(array, size);
        }
    }
}
