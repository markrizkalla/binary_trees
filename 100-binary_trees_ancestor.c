#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;
	int node1l = 0, node2l = 0;

	while (node1->parent != NULL)
	{
		node1 = node1->parent;
		node1l++;
	}
	while (node2->parent != NULL)
	{
		node2 = node2->parent;
		node2l++;
	}
	node1 = first;
	node2 = second;
	while (node1l < node2l)
	{
		node2 = node2->parent;
		node2l--;
	}
	while (node2l < node1l)
	{
		node1 = node1->parent;
		node1l--;
	}
	while (node1 != NULL && node2 != NULL)
	{
		if (node1 == node2)
		{
			return ((binary_tree_t *)node1);
		}
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return ((binary_tree_t *)node1);
}
