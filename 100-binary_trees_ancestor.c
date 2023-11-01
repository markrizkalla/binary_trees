#include "binary_trees.h"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	const binary_tree_t *node1 = first;

	const binary_tree_t *node2 = second;

	int node1l = 0;
	
	int node2l = 0;

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

	while (node1l < node2l)
	{
		node1 = node1->parent;
		node1l++;
	}

	node2 = second;

	while (node2l < node1l)
	{
		node2 = node2->parent;
		node2l++;
	}

	while (node1 != NULL && node2 != NULL)
	{
    		if (node1 == node2)
        		return ((binary_tree_t *)node1);

    		if (node1l > node2l)
    		{
        		node1 = node1->parent;
        		node1l--;
    		}
    		else if (node2l > node1l)
    		{
        		node2 = node2->parent;
        		node2l--;
    		}
    		else
    		{
        		node1 = node1->parent;
        		node2 = node2->parent;
        		node1l--;
       			node2l--;
    		}
}

    	if (node1 == NULL || node2 == NULL)
	{

        	return (NULL);
	}


	return ((binary_tree_t *)node1);
}
