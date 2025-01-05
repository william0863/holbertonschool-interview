#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the elements of an array
 * @array: array
 * @start: start of subarray
 * @end: end of subarray
 */
void print_array(int *array, size_t start, size_t end)
{
    size_t i;

    printf("Searching in array: ");
    for (i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary_search - Recursively searches for a value in a sorted array
 * @array: array
 * @start: start of subarray
 * @end: end of subarray
 * @value: value to search
 *
 * Return: The index of the value
 */
int recursive_binary_search(int *array, size_t start, size_t end, int value)
{
    size_t mid;

    if (start > end)
        return (-1);

    print_array(array, start, end);

    mid = start + (end - start) / 2;

    if (array[mid] == value && (mid == start || array[mid - 1] != value))
        return ((int)mid);

    if (array[mid] >= value)
        return (recursive_binary_search(array, start, mid, value));
    else
        return (recursive_binary_search(array, mid + 1, end, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search
 * @array: array
 * @size: size of the array
 * @value: The value to search
 *
 * Return: The index of the value
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (!array || size == 0)
        return (-1);

    return (recursive_binary_search(array, 0, size - 1, value));
}

