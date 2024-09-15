#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

typedef struct queue_node_s
{
heap_t *tree_node;
struct queue_node_s *next;
} queue_node_t;

heap_t *find_first_available(heap_t *root);
void swap_values(heap_t *node1, heap_t *node2);
heap_t *heapify_up(heap_t *node);
void enqueue(queue_node_t **queue, heap_t *tree_node);
heap_t *dequeue(queue_node_t **queue);
void free_queue(queue_node_t *queue);

/**
 * heap_insert - insert a value for max heap
 * @root: double pointer to root
 * @value: Value
 *
 * Return: null if fail 
 * */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node = malloc(sizeof(heap_t));

if (new_node == NULL)
{
return (NULL);
}

new_node->n = value;
new_node->left = NULL;
new_node->right = NULL;
new_node->parent = NULL;

if (*root == NULL)
{
*root = new_node;
return (new_node);
}

heap_t *first_available = find_first_available(*root);

if (first_available == NULL)
{
free(new_node);
return (NULL);
}

new_node->parent = first_available;
if (first_available->left == NULL)
first_available->left = new_node;
else
first_available->right = new_node;

return (heapify_up(new_node));
}

/**
 * find_first_available - finds first node with child available
 * @root: root
 *
 * Return: pointer to the first node
 */
heap_t *find_first_available(heap_t *root)
{
queue_node_t *queue = NULL;
heap_t *current;

enqueue(&queue, root);
while (queue != NULL)
{
current = dequeue(&queue);

if (current->left == NULL || current->right == NULL)
{
free_queue(queue);
return (current);
}

if (current->left != NULL)
{
enqueue(&queue, current->left);
}

if (current->right != NULL)
{
enqueue(&queue, current->right);
}
}

free_queue(queue);
return (NULL);
}

/**
 * swap_values - swaps values of node
 * @node1: first node
 * @node2: second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_up - r
 * @node: node
 *
 * Return: pointer to the new node
 */
heap_t *heapify_up(heap_t *node)
{
while (node->parent && node->n > node->parent->n)
{
swap_values(node, node->parent);
node = node->parent;
}
return (node);
}

/**
 * enqueue - adds item at end of queue
 * @queue: queue
 * @tree_node: tree node
 */
void enqueue(queue_node_t **queue, heap_t *tree_node)
{
queue_node_t *new_node = malloc(sizeof(queue_node_t));

if (new_node == NULL)
return;

new_node->tree_node = tree_node;
new_node->next = NULL;

if (*queue == NULL)
{
*queue = new_node;
}
else
{
queue_node_t *temp = *queue;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = new_node;
}
}

/**
 * dequeue - deletes the first item from the queue
 * @queue: queue
 *
 * Return: the dequeued tree node or null if queue is empty
 */
heap_t *dequeue(queue_node_t **queue)
{
if (*queue == NULL)
{
return (NULL);
}

queue_node_t *temp = *queue;
heap_t *node = temp->tree_node;
*queue = (*queue)->next;
free(temp);

return (node);
}

/**
 * free_heap - Frees all nodes in the heap
 * @root: Pointer to the root node of the heap
 */
void free_queue(queue_node_t *queue)
{
queue_node_t *temp;

while (queue != NULL)
{
temp = queue;
queue = queue->next;
free(temp);
}
}

