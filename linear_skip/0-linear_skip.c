#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 *
 * @list: Pointer to head of the list
 * @value: Value to search
 *
 * Return: Pointer to the node, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *current;

	if (!list)
		return (NULL);

	prev = list;
	current = list->express;

	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n >= value)
			break;
		prev = current;
		current = current->express;
	}

	if (!current || current->n < value)
	{
		current = prev;
		while (current->next)
			current = current->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);

	for (; prev && prev->index <= current->index; prev = prev->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
		    return (prev);
	}

	return (NULL);
}
