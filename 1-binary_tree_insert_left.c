#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 *
 * @parent: A pointer to the node to insert the left child in.
 * @value: The value to store the new node.
 *
 * Return: A pointer to the created node, NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	if (parent->left != NULL)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;

	return (node);
}
