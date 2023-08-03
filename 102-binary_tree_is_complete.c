#include <stdlib.h>
#include "binary_trees.h"

/**
 * count_nodes - Count the number of nodes in a binary tree.
 *
 * @tree: Pointer to the root node of the tree to count.
 *
 * Return: Number of nodes in the tree.
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Recursive helper function to check if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @index: Current index of the node.
 * @count: Number of nodes in the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, int index, int count)
{
	if (tree == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, count) &&
	        is_complete(tree->right, 2 * index + 2, count));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count;

	if (tree == NULL)
		return (0);

	count = count_nodes(tree);

	return (is_complete(tree, 0, count));
}
