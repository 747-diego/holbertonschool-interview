#include "sort.h"


/**
 * swapNode - swaps nodes
 * @array: array to sort
 * @currentNode: current index in array
 * @farNode: farther node in array
 * Return: void
 */
void swapNode(int *array, int currentNode, int farNode)
{
	int swap;

	swap = array[farNode];
	array[farNode] = array[currentNode];
	array[currentNode] = swap;
}


/**
 * checkLeft - checks left side of node
 * @array: array to sort
 * @farNode: farther node in array
 * @left: left node
 * @nodePosition: pos of node
 * Return: void
 */
int checkLeft(int *array, int farNode, int left, int nodePosition)
{
	if (left < nodePosition && array[left] > array[farNode])
	{
		farNode = left;
	}
	return (farNode);
}

/**
 * checkRight - checks left side of node
 * @array: array to sort
 * @farNode: farther node in array
 * @right: right node
 * @nodePosition: pos of node
 * Return: void
 */
int checkRight(int *array, int farNode, int right, int nodePosition)
{
	if (right < nodePosition && array[right] > array[farNode])
	{
		farNode = right;
	}
	return (farNode);
}

/**
 * sortArray - sorts the array for heap
 * @array: array to sort
 * @nodePosition: pos of node
 * @currentNode: current index in array
 * @arrayLength: size of array
 * Return: void
 */
void sortArray(int *array, int nodePosition, int currentNode, int arrayLength)
{
	int farNode = currentNode;
	int doubled = currentNode * 2;
	int left = doubled + 1;
	int right = doubled + 2;

	farNode = checkLeft(array, farNode, left, nodePosition);
	farNode = checkRight(array, farNode, right, nodePosition);

	if (farNode != currentNode)
	{
		swapNode(array, currentNode, farNode);
		print_array(array, arrayLength);
		sortArray(array, nodePosition, farNode, arrayLength);
	}
}


/**
 * heap_sort - a function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: array length
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int farNode;
	int node;

	if (!size || !array)
		return;

	for (node = size / 2 - 1; node >= 0; node--)
		sortArray(array, size, node, size);
	for (node = size - 1; node > 0; node--)
	{
		if (array[0] >= array[node])
		{
			farNode = 0;
			swapNode(array, node, farNode);
			print_array(array, size);
		}
		sortArray(array, node, 0, size);
	}
}
