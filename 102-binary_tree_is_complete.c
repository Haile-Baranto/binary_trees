#include "binary_trees.h"

/**
 * is_complete - Recursive helper function to check if
 * a binary tree is complete.
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
	int count = 0;
	const binary_tree_t *node = tree;

	if (tree == NULL)
		return (0);

	while (node != NULL)
	{
		count++;
		node = node->left;
	}

	return (is_complete(tree, 0, count));
}
