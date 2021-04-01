#include "search.h"

/**
  * linear_skip -  searches for a value in a sorted skip list of integers.
  * @list: sorted in ascending order
  * @value: not present in list or if head is NULL
  * Return: NULL
  */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *nodeOne;
	skiplist_t *nodeTwo;
	int valueOne;
	int valueTwo;


	if (list == NULL)
	{
		return (NULL);
	}

	while (nodeTwo->next && nodeTwo->n < value)
	{
		nodeOne = nodeTwo;
		if (nodeTwo->express)
		{
			nodeTwo = nodeTwo->express;
			printf("Value checked at index [%lu] = [%d]\n",
				(int)nodeTwo->index, nodeTwo->n);
		}
		else
		{
			while (nodeTwo->next)
				nodeTwo = nodeTwo->next;
		}
	}
	valueOne = (int)nodeOne->index;
	valueTwo = (int)nodeTwo->index;
	printf("Value found between indexes [%lu] and [%lu]\n", valueOne, valueTwo);
	while (nodeOne && valueOne <= valueTwo)
	{
		printf("Value checked at index [%lu] = [%d]\n", valueOne, nodeOne->n);
		if (nodeOne->n == value)
		{
			return (nodeOne);
		}
		valueOne++;
		nodeOne = nodeOne->n;
	}
	return (NULL);
}
