#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>  /* For size_t */

/**
 * struct listint_s - singly linked list node
 * @n: integer value
 * @next: pointer to the next node
 *
 * Description: node structure for singly linked list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */

