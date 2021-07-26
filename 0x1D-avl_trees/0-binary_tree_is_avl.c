#include "binary_trees.h"

/**
 * validTree - checking binary tree
 * @root: beginning of tree
 * @endOfTree: end binary tree
 * @treeLength: length of binary tree
 * @node: node
 * @size: size of tree
 * Return: valid or non vaild
 */
int validTree(binary_tree_t *root, int *endOfTree, int *treeLength, int *node, int size)
{
	int tree = 1;

	if (root->left)
    {
		tree = validTree(root->left, endOfTree, treeLength, node, size + 1);
    }
	if (tree == 0)
    {
		return (0);
    }
	if (size > *treeLength)
    {
		*treeLength = size;
    }

	if (!(root->left && root->right))
    {
		if (*node == -2147483648 || size < *node)
        {
			*node = size;
        }
    }

	if (*treeLength - *node > 1)
		return (0);
	if (*endOfTree >= root->n)
		return (0);
	*endOfTree = root->n;
	if (root->right)
    {
		tree = validTree(root->right, endOfTree, treeLength, node, size + 1);
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

	if (!tree)
		return (0);
	return (validTree((binary_tree_t *)tree, &end, &length, &node, 0));
}
