

#include "binary_trees.h"

/**
 * swap_nodes - swap two nodes pointers
 * @firstNode: node one
 * @secondNode: node two
 */
void swap(heap_t *firstNode, heap_t *secondNode)
{
	if (firstNode == secondNode)
		return;
	firstNode->n = (firstNode->n) ^ (secondNode->n);
	secondNode->n = (firstNode->n) ^ (secondNode->n);
	firstNode->n = (firstNode->n) ^ (secondNode->n);
}


int check(int left, int right)
{
    if (left > right)
    {
		return (left);
    }
	return (right);
}


void checkLeft(heap_t *firstNode, int shiftLeft, int length, int lengthSum)
{
    if (firstNode->left)
    { 
		shiftLeft = findSize(firstNode->left, lengthSum);
    }
	else
    {
		shiftLeft = length;
    }

}

void checkRight(heap_t *firstNode, int shiftRight, int length, int lengthSum)
{
    if (firstNode->right)
    {
		shiftRight = findSize(firstNode->right, lengthSum);
    }
	else
    {
		shiftRight = length;
    }
}
