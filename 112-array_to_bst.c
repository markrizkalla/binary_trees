#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t index = 0;

	if (array == NULL)
		return (NULL);

	tree = malloc(sizeof(bst_t));
	tree->n = array[index++];

	while (index < size)
	{
		int val = array[index];
		bst_t *curr = tree;

		while (curr != NULL)
		{
			bst_t **next = (val < curr->n) ? &curr->left : &curr->right;

			if (*next)
				curr = *next;
			else
			{
				*next = malloc(sizeof(bst_t));
				(*next)->n = val;
				(*next)->parent = curr;
				break;
			}
		}
		index++;
	}
	return (tree);
}
