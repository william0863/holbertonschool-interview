#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - A function that creates a tree node
 * @parent: Pointer to parent node
 * @value: Value to store in new node
 *
 * Return: Pointer to node
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl_tree - A function that creates an AVL tree recursively
 * @array: array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to parent
 *
 * Return: Pointer to the root node of subtree
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_avl_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl_tree(array, start, mid - 1, root);
	root->right = build_avl_tree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - A function that creates an AVL tree from an array
 * @array: Array from where we build tree
 * @size: size of array
 *
 * Return: Pointer to new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, NULL));
}
