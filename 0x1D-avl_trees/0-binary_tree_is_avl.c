#include "binary_trees.h"

/**
 * validTree - tree to determine whethere it is valid
 * @head: first ptr
 * @tailnode: last ptr
 * @lengthOfTree: size of ptr's
 * @beginningOfTree: first ptr
 * @sizeOfTree: size of all ptr's
 * Return: tree
 */
int validTree(binary_tree_t *head, int *tailnode, int *lengthOfTree, int *beginningOfTree, int sizeOfTree)
{
	int tree = 1;
    int num = -2147483648;

    if (tree == 0)
    {
		return (0);
    }
	if (head->left)
    {
		tree = validTree(node->left, tailnode, lengthOfTree, beginningOfTree, sizeOfTree + 1);
    }
	if (sizeOfTree > *lengthOfTree)
		*lengthOfTree = sizeOfTree;
	if (!(head->left && head->right))
    {
		if (*beginningOfTree == num || sizeOfTree < *beginningOfTree)
        {
			*beginningOfTree = sizeOfTree;
        }
    }
	if (*lengthOfTree - *beginningOfTree > 1)
    {
		return (0);
    }
	if (*tailnode >= head->n)
    {
		return (0);
    }
	*tailnode = head->n;
	if (head->right)
		tree = validTree(head->right, tailnode, lengthOfTree, beginningOfTree, sizeOfTree + 1);
	if (tree == 0)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - tree is valid
 * @tree: tree
 * Return: valid or non valid
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int num = -2147483648;

	if (tree == NULL)
		return (0);
	return (validTree((binary_tree_t *)tree, &num, &num, &num, 0));
}
