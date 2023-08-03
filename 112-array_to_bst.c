#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 *
 * @tree: Pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Delete the left subtree */
	binary_tree_delete(tree->left);

	/* Delete the right subtree */
	binary_tree_delete(tree->right);

	/* Delete the current node */
	free(tree);
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			/* Free the already built tree on failure */
			binary_tree_delete(root);
			return (NULL);
		}
	}

	return (root);
}
