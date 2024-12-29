#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element to swap
 * @b: Second element to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Ensures the heap property by sifting down
 * @array: The array representing the heap
 * @size: Total size of the array
 * @root: Root index of the subtree to sift down
 * @end: The index of the last element in the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left <= end && array[left] > array[largest])
        largest = left;

    if (right <= end && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size);
        sift_down(array, size, largest, end);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (!array || size < 2)
        return;

    for (i = (size / 2) - 1; (int)i >= 0; i--)
        sift_down(array, size, i, size - 1);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, size, 0, i - 1);
    }
}

