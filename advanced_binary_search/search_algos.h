#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

int advanced_binary(int *array, size_t size, int value);
void print_array(int *array, size_t start, size_t end);
int recursive_binary_search(int *array, size_t start, size_t end, int value);

#endif /* SEARCH_ALGOS_H */

