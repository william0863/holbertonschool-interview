#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_insert_position - finds the next insertion point in a binary heap
 *
 * @root: Pointer to the root of the tree
 * Return: Pointer to the node where the new value should be inserted
 */
binary_tree_t *find_insert_position(binary_tree_t *root)
{
    binary_tree_t *queue[1024];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear)
    {
        binary_tree_t *node = queue[front++];

        if (node->left == NULL || node->right == NULL)
            return (node);

        queue[rear++] = node->left;
        queue[rear++] = node->right;
    }
    return (NULL);
}

/**
 * heapify_up - Reorders the binary heap by sifting a node upwards
 *
 * @node: Pointer to the node to sift up
 */
void heapify_up(heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;

        node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root of the heap
 * @value: Value to insert into the heap
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *insert_position;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    insert_position = find_insert_position(*root);
    new_node = binary_tree_node(insert_position, value);
    if (new_node == NULL)
        return (NULL);

    if (insert_position->left == NULL)
        insert_position->left = new_node;
    else
        insert_position->right = new_node;

    heapify_up(new_node);

    return (new_node);
}

