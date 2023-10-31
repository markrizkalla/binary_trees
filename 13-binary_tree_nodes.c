#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t nodesN = 0;

	if (tree)
	{
		nodesN += tree->right || tree->left ? 1 : 0;
		nodesN += binary_tree_nodes(tree->right);
		nodesN += binary_tree_nodes(tree->left);
	}

	return (nodesN);
}
