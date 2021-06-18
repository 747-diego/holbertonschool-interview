#include "search_algos.h"

/**
 * showArray - displays array
 * @currentNode: node index
 * @newNode: node to lead the lenght of array
 * @array: array to sort
 * Return: void
 */
void showArray(int currentNode, int newNode, int *array)
{
    int node;
    char newLine[] = "\n";
    char sep[] = ", ";
    char messageDisplay[] = "Searching in array: ";
    int nodePos = newNode + 1;

	printf("%s", messageDisplay);
	while (currentNode <= newNode)
	{
        node = array[currentNode++];
		printf("%d", node);
		if (currentNode != nodePos)
			printf("%s", sep);
	}
	printf("%s", newLine);
}

/**
 * valueSearch - searches for value in binary tree
 * @currentNode: node index
 * @newNode: node to lead the length of array
 * @num: number inside node
 * @array: array to sort
 * @length: array length
 * Return: num
 */
int valueSearch(int currentNode, int newNode, int num, int *array, int length)
{
    int nodeDividend = (newNode - currentNode) / 2;
	int nodeSum = currentNode + nodeDividend;
    int nodeIndex = array[currentNode];
    int notPresentORnull = -1;

	showArray(currentNode, newNode, array);
	if (nodeIndex == num)
    {
		return (currentNode);
    }


	if (newNode - currentNode != 0)
	{
		if (num > array[nodeSum])
        {
			currentNode = nodeSum + 1;
        }
		else
		{
            newNode = nodeSum;
        }

		return (valueSearch(currentNode, newNode, num, array, length));
	}

	return (notPresentORnull);
}


/**
 * advanced_binary - this function finds the first value of in the search.
 * @array: array
 * @size: length of the array
 * @value: number inside of node
 * Return: value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
    {
		return (-1);
    }
	else 
    {
        return (valueSearch(0, size - 1, value, array, size));
    }
}
