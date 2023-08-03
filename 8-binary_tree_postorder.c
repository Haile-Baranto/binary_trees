#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 *
 * Description: The function traverses the tree in post-order and applies the
 * function `func` to each node's value.
 * If `tree` or `func` is NULL, the function does nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
