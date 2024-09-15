#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
typedef struct queue_node_s
{
	heap_t *tree_node;
	struct queue_node_s *next;
} queue_node_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const binary_tree_t *);
heap_t *find_first_available(heap_t *root);
void swap_values(heap_t *node1, heap_t *node2);
heap_t *heapify_up(heap_t *node);
void enqueue(queue_node_t **queue, heap_t *tree_node);
heap_t *dequeue(queue_node_t **queue);
void free_queue(queue_node_t *queue);

#endif
