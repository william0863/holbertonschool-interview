#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - new node to the end of list
 * @list: list
 * @str: string to copy
 *
 * Return: new node
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tail;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		tail = (*list)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *list;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - new node to the beginning of list
 * @list: list
 * @str: string to copy in new node
 *
 * Return: new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = add_node_end(list, str);
	if (new_node)
		*list = new_node;

	return (new_node);
}
