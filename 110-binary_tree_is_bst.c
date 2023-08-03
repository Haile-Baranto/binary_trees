#include <limits.h>
#include "binary_trees.h"

/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @prev: Pointer to the previous node's value in inorder traversal.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
static int is_bst_util(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_util(tree->left, prev))
		return (0);

	if (tree->n <= *prev)
		return (0);

	*prev = tree->n;

	return (is_bst_util(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	return (is_bst_util(tree, &prev));
}
