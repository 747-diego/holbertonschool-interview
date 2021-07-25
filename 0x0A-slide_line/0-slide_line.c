#include "slide_line.h"

/**
 * shiftingRight - move node
 * @nodes: nodes
 * @lengthOfNodeList: length of node array
 */
void shiftingRight(int *nodes, size_t lengthOfNodeList)
{
	size_t nodeOne;
	size_t nodeTwo;

	for (nodeOne = 1; nodeOne <= lengthOfNodeList; nodeOne++)
	{
		for (nodeTwo = nodeOne + 1; nodeTwo <= lengthOfNodeList; nodeTwo++)
		{
			if (nodes[lengthOfNodeList - nodeOne] == 0 && nodes[lengthOfNodeList - nodeTwo] != 0)
			{
				nodes[lengthOfNodeList - nodeOne] = nodes[lengthOfNodeList - nodeTwo];
				nodes[lengthOfNodeList - nodeTwo] = 0;
				nodeOne -= 1;
				break;
			}
			if (nodes[lengthOfNodeList - nodeOne] == nodes[lengthOfNodeList - nodeTwo] && nodes[lengthOfNodeList - nodeOne] != 0)
			{
				nodes[lengthOfNodeList - nodeOne] = nodes[lengthOfNodeList - nodeOne] * 2;
				nodes[lengthOfNodeList - nodeTwo] = 0;
				break;
			}
			else if (nodes[lengthOfNodeList - nodeTwo] != 0 && nodes[lengthOfNodeList - (nodeOne + 1)] == 0)
			{
				nodes[lengthOfNodeList - (nodeOne + 1)] = nodes[lengthOfNodeList - nodeTwo];
				nodes[lengthOfNodeList - nodeTwo] = 0;
				break;
			}
		}
	}
}

/**
 * shiftingLeft - move node
 * @nodes: nodes
 * @lengthOfNodeLIst: length of node array
 */
void shiftingLeft(int *nodes, size_t lengthOfNodeList)
{
	size_t numOne;
	size_t numTwo;

	for (numOne = 0; numOne < lengthOfNodeList; numOne++)
	{
		for (numTwo = numOne + 1; numTwo < lengthOfNodeList; numTwo++)
		{
			if (nodes[numOne] == 0 && nodes[numTwo] != 0)
			{
				nodes[numOne] = nodes[numTwo];
				nodes[numTwo] = 0;
				numOne--;
				break;
			}
			if (nodes[numOne] == nodes[numTwo] && nodes[numOne] != 0)
			{
				nodes[numOne] *= 2;
				nodes[numTwo] = 0;
				break;
			}
			else if (nodes[numTwo] != 0 && nodes[numOne + 1] == 0)
			{
				nodes[numOne + 1] = nodes[numTwo];
				nodes[numTwo] = 0;
				break;
			}
		}
	}
}

/**
 * slide_line - slides and merges an array of node content
 * @line: node list
 * @size: size of node list
 * @direction: left or right
 * Return: 1 or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
	{
		return (0);
	}
	if (direction == 76)
	{
		shiftingLeft(line, size);
	}
	else if (direction == 82)
	{
		shiftingRight(line, size);
	}
	else
	{
		return (0);
	}
	return (1);
}
