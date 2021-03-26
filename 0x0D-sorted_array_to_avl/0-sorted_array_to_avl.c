#include "binary_trees.h"



/**
* newNode - temporary node
* Return: temp node
* @parent: prev node from struct
* @key: node content
*/
binary_tree_t *newNode(int key, binary_tree_t *parent)
{
    binary_tree_t *prev = parent;
    binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
    {
		return (NULL);
    }
	node->n = key;
    node->parent = prev;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


/**
* treeNode - a function that sorts the tree being built
* Return: sorted tree
* @array: is a pointer to the first element of the array to be converted
* @size: is the number of element in the array
*/
avl_t *treeNode(int *array, size_t size)
{
    avl_t *tempNode;
    size_t div = size / 2;
    unsigned int sizeOfArray = div - (1 - size % 2);


	if (array == 0)
    {
		return (NULL);
    }
    if (size == 0)
    {
        return (NULL);
    }


	tempNode = newNode(array[sizeOfArray], NULL);
	if (tempNode == NULL)
    {
		return (NULL);
    }


	tempNode->left = sorted_array_to_avl(array, sizeOfArray);
	if (tempNode->left)
    {
        tempNode->left->parent = tempNode;
    }

	tempNode->right = sorted_array_to_avl(&array[sizeOfArray++], div);
	return (tempNode);
}


/**
* sorted_array_to_avl - a function that builds an AVL tree from an array
* Return: a pointer to the root node of the created AVL tree, or NULL
* @array: is a pointer to the first element of the array to be converted
* @size: is the number of element in the array
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{

    if (!array || !size)
    {
        return (NULL);
    }

    return (treeNode(array, size));

}
