#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node at right of parent
 * @parent: A pointer to the node to insert the right child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
	{
		return (NULL);
	}

	node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		return (NULL);
	}

	node->n = value;
	node->right = NULL;
	node->left = NULL;
	node->parent = parent;

	if (parent->right != NULL)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}

	parent->right = node;

	return (node);
}
