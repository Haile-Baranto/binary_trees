#include <stdlib.h>
#include "binary_trees.h"

/**
 * max - Get the maximum of two integers
 *
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of @a and @b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Calculate the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, -1 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * binary_tree_is_bst - Check if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n >= tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n <= tree->n)
		return (0);

	return (binary_tree_is_bst(tree->left) &&
		binary_tree_is_bst(tree->right));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	left_height = height(tree->left);
	right_height = height(tree->right);

	balance_factor = left_height - right_height;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right) &&
		binary_tree_is_bst(tree));
}
