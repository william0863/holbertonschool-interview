#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/**
 * struct List - doubly linked list
 * @str: string
 * @prev: previous node
 * @next: next node
 *
 * Description: doubly linked list
 *
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */

