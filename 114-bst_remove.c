#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: Pointer to the root node of the tree where you will
 * remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: A pointer to the new root node of the tree after
 * removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	 bst_t *temp;
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Found the node to remove */
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		/* Node has two children, find in-order successor */
		temp = root->right;
		while (temp && temp->left != NULL)
			temp = temp->left;

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
