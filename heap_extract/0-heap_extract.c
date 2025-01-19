#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Restores the max heap property by sifting down a node.
 * @node: Pointer to the node to sift down.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;
    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        int temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * get_last_node - Gets the last node in level-order traversal.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t **queue;
    size_t head = 0, tail = 0;
    heap_t *last = NULL;

    queue = malloc(1024 * sizeof(heap_t *));
    if (!queue)
        return (NULL);

    queue[tail++] = root;
    while (head < tail)
    {
        last = queue[head++];
        if (last->left)
            queue[tail++] = last->left;
        if (last->right)
            queue[tail++] = last->right;
    }

    free(queue);
    return (last);
}

/**
 * heap_extract - Extracts the root value of a max binary heap.
 * @root: Double pointer to the root of the heap.
 *
 * Return: The value stored in the root node, or 0 if the function fails.
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last, *parent;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    last = get_last_node(*root);
    if (!last)
        return (0);

    (*root)->n = last->n;
    parent = last->parent;
    if (parent->left == last)
        parent->left = NULL;
    else
        parent->right = NULL;

    free(last);
    heapify_down(*root);

    return (value);
}

