#include "binary_trees.h"

/**
 * validTree - checking binary tree
 * @root: beginning of tree
 * @endTree: end binary tree
 * @len: length of binary tree
 * @node: node
 * @size: size of tree
 * Return: valid or non vaild
 */
int validTree(binary_tree_t *root, int *endTree, int *len, int *node, int size)
{
	int num = -2147483648, tree = 1;

	if (root->left)
	{
		tree = validTree(root->left, endTree, len, node, size + 1);
	}
	if (size > *len)
	{
		*len = size;
	}
	if (tree == 0)
	{
		return (0);
	}

	if (!(root->left && root->right))
	{
		if (*node == num || size < *node)
		{
			*node = size;
		}
	}

	if (*len - *node > 1)
		return (0);
	if (*endTree >= root->n)
		return (0);
	*endTree = root->n;
	if (root->right)
	{
		tree = validTree(root->right, endTree, len, node, size + 1);
	}
	if (tree == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - checking if valid
 * @tree: head node
 * Return: check if valid or non valid
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int node = -2147483648, end = -2147483648, length = -2147483648;

	if (tree == NULL)
		return (0);
	return (validTree((binary_tree_t *)tree, &end, &length, &node, 0));
}

