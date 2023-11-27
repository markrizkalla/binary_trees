#include "binary_trees.h"
#include <limits.h>

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int min, int max);
int height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited thus far.
 * @max: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		int leftH = height(tree->left);
		int rightH = height(tree->right);
		if (abs(leftH - rightH) > 1)
			return (0);
		return (is_avl_helper(tree->left, min, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
int height(const binary_tree_t *tree)
{
  if (tree == NULL)
    return (0);

  int leftHeig = height(tree->left);
  int rightHei = height(tree->right);

  return (leftHeig > rightHei ? leftHeig + 1 : rightHei + 1);
}
