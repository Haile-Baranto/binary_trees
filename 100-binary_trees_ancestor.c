#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *ancestor_first, *ancestor_second;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor_first = (binary_tree_t *)first;
	while (ancestor_first != NULL)
	{
		ancestor_second = (binary_tree_t *)second;
		while (ancestor_second != NULL)
		{
			if (ancestor_first == ancestor_second)
				return (ancestor_first);
			ancestor_second = ancestor_second->parent;
		}
		ancestor_first = ancestor_first->parent;
	}

	return (NULL);
}
