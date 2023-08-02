#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Is a pointer to the parent node to be created
 * @value: the value to be stored on the node
 * Return: If sucess A pointer to the new node else NULL
 * Description: when cretaed the root node will have not child
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *root;

	root = malloc(sizeof(binary_tree_t));
	if (!root)
	{
		return (NULL);
	}
	root->parent = parent;
	root->n = value;
	root->left = root->right = NULL;
	return (root);
}
