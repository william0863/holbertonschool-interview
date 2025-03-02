#include "sort.h"
#include <stdlib.h>

/**
 * get_max - finds the maximum number
 * @array: array
 * @size: size of array
 *
 * Return: maximum number
 */
int get_max(int *array, size_t size)
{
    int max;
    size_t i;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - Sorts the array using count
 * @array: array to sort
 * @size: size of array
 * @exp: The exponent
 *
 * Return: void
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output;
    int count[10] = {0};
    int i;
    size_t j;

    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    for (j = 0; j < size; j++)
        count[(array[j] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (j = 0; j < size; j++)
        array[j] = output[j];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array using Radix Sort
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
    int max;
    int exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort(array, size, exp);
}

