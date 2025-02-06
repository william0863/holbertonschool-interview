#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the new head.
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    if (!head || !*head || !(*head)->next)
        return 1;

    listint_t *slow = *head, *fast = *head, *second_half, *reversed;
    
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    second_half = reverse_list(slow);
    reversed = second_half;
    listint_t *first_half = *head;
    
    while (second_half)
    {
        if (first_half->n != second_half->n)
        {
            reverse_list(reversed);
            return 0;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    
    reverse_list(reversed);
    return 1;
}

