#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array of integers.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (size == 0 || array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Insert unique elements into the AVL tree */
		if (avl_insert(&root, array[i]) == NULL)
		{
			/* Free the already built AVL tree on failure */
			avl_delete(root);
			return (NULL);
		}
	}

	return (root);
}
