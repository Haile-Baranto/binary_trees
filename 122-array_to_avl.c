#include "binary_trees.h"

/**
 * array_to_avl - Converts an array to an AVL tree.
 * @array: Pointer to the first element of the array to
 * be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL
 * tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
    size_t i, j = 0;
    avl_t *root;

    root = NULL;
    if (size == 0)
    {
        return (NULL);
    }
    for (i = 0; i < size; i++)
    {
        /* Check for duplicates in the array */
        for (j = 0; j < i; j++)
        {
            if (array[j] == array[i])
                break;
        }
        /* Insert unique elements into the AVL tree */
        if (j == i)
        {
            if (avl_insert(&root, array[i]) == NULL)
            {
                /* Free the already built AVL tree on failure */
                return (NULL);
            }
        }
    }
    return (root);
}
