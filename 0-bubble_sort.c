#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: A pointer to the first integer to swap.
 * @b: A pointer to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using bubble sort algorithm.
 * @array: A pointer to an array of integers.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bool sorted = false;  // A flag to monitor if swaps were made during the iteration
    size_t length = size;

    while (!sorted)
    {
        sorted = true;
        for (size_t i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_ints(&array[i], &array[i + 1]);
                print_array(array, size);  // Assuming print_array is defined elsewhere
                sorted = false;
            }
        }
        length--;
    }
}
