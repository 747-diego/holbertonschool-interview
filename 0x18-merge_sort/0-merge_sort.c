#include "sort.h"


/**
 * displayNodes - shows the merging nodes
 * @array: array
 * @headNode: beginning node
 * @tailNode: ending node
 * Return: nothing
 */
void displayNodes(int array[], size_t headNode, size_t tailNode)
{
	while (headNode < tailNode)
	{
		printf("%d", array[headNode]);
		if (headNode < tailNode - 1)
		{
			printf(", ");
		}
		headNode++;
	}
}


/**
 * nodeSwap - switches sides with the nodes
 * @array: array
 * @headNode: beginning node
 * @bodyNode: halfway mark
 * @tailNode: ending node
 * @currentArray: final array to host
 * Return: nothing
 */
void nodeSwap(int array[], size_t headNode, size_t bodyNode,
	size_t tailNode, int currentArray[])
{
	size_t tempNodeOne = headNode;
	size_t tempNodeTwo = bodyNode, node;

	printf("[left]: ");
	displayNodes(array, headNode, bodyNode);
	printf("\n");

	printf("[right]: ");
	displayNodes(array, bodyNode, tailNode);
	printf("\n");

	for (node = headNode; node < tailNode; node++)
	{
		if (tempNodeOne < bodyNode && (tempNodeTwo >= tailNode ||
			array[tempNodeOne] <= array[tempNodeTwo]))
		{
			currentArray[node] = array[tempNodeOne];
			tempNodeOne += 1;
		}
		else
		{
			currentArray[node] = array[tempNodeTwo];
			tempNodeTwo += 1;
		}
	}
	printf("[Done]: ");
	displayNodes(currentArray, headNode, tailNode);
	printf("\n");
}


/**
 * split - this function recursivly splits the array then merges
 * @currentNode: final array
 * @headNode: start index
 * @tailNode: end index
 * @array: array
 * Return: void
 */
void split(int currentNode[], size_t headNode, size_t tailNode, int array[])
{
	size_t node = (tailNode + headNode) / 2;
	size_t nodeSub = tailNode - headNode;

	if (nodeSub <= 1)
	{
		return;
	}
	split(array, headNode,  node, currentNode);
	split(array, node, tailNode, currentNode);
	printf("Merging...\n");
	nodeSwap(array, headNode, node, tailNode, currentNode);
}

/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: the array we will sort
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t node = 0;
	int zero = 0;
	int *currentArray = NULL;


	if (size < 2 || array == currentArray)
	{
		return;
	}

	currentArray = malloc(size * sizeof(size));
	if (currentArray == NULL)
	{
		return;
	}

	while (node < size)
	{
		currentArray[node] = array[node];
		node++;
	}
	split(currentArray, zero, size, array);
	node = 0;
	while (node < size)
	{
		array[node] = currentArray[node];
		node++;
	}
	free(currentArray);
}
