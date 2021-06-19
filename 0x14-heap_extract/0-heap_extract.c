#include "binary_trees.h"



/**
 * findSize - find the length of array
 * @firstNode: ptr to head
 * @length: size of array
 * Return: size
 */
int findSize(heap_t *firstNode, int length)
{
	int shiftLeft = 0;
	int shiftRight = 0;
	int lengthSum = length + 1;
	int checkDirection;

	checkLeft(firstNode, shiftLeft, length, lengthSum);
	checkRight(firstNode, shiftRight, length, lengthSum);
	checkDirection = check(shiftLeft, shiftRight);
	return (checkDirection);
}

/**
 * grabNode - grabbing end node
 * @firstNode: ptr to head
 * @length: lengt of array
 * @lastNode: end point
 * Return: shifted node
 */
heap_t *grabNode(heap_t *firstNode, int length, int lastNode)
{
	heap_t *shiftLeft;
	heap_t *shiftRight;
	int lengthSum = length + 1;

	if (length == lastNode)
	{
		return (firstNode);
	}
	shiftLeft = NULL;
	shiftRight = NULL;

	if (firstNode->left)
	{
		shiftLeft = grabNode(firstNode->left, lengthSum, lastNode);
	}
	if (firstNode->right)
	{
		shiftRight = grabNode(firstNode->right, lengthSum, lastNode);
	}
	if (shiftRight)
	{
		return (shiftRight);
	}
	return (shiftLeft);
}

/**
 * heap_extract - grab node
 * @root: beginning node
 * Return: num inside if node
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *tempNode;
	heap_t *left, *right;
	int num = 0;



	if (root == NULL)
	{
		return (num);
	}
	if (*root == NULL)
	{
		return (num);
	}
	num = (*root)->n;
	node = grabNode(*root, 0, findSize(*root, 0));
	if (node == *root)
	{
		free(node);
		*root = NULL;
		return (num);
	}
	swap(*root, node);
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	}
	else
	{
		node->parent->right = NULL;
	}
	free(node);
	node = *root;
	while (1)
	{
		left = node->left;
		right = node->right;
		tempNode = left;
		if (left && right && (left->n < right->n))
		{
			tempNode = right;
		}
		if (left == NULL && right == NULL)
		{
			break;
		}
		if (tempNode->n > node->n)
		{
			swap(node, tempNode);
		}
		else
		{
			break;
		}
		node = tempNode;
	}
	return (num);
}
