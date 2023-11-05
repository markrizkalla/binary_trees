#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 *
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing a value equals to value.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	bst_t *curr = (bst_t *)tree;

	while (curr != NULL)
	{
		if (value < curr->n)
		{
			curr = curr->left;
		} else if (value > curr->n)
		{
			curr = curr->right;
		}else
		{
			return (curr);
		}
	}

	return (NULL);
}
