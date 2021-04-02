#include "search.h"

/**
  * linear_skip -  searches for a value in a sorted skip list of integers.
  * @list: sorted in ascending order
  * @value: not present in list or if head is NULL
  * Return: NULL
  */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *nodeOne = list->express;
	skiplist_t *nodeTwo = list;

	if (list == NULL)
	{
		return (NULL);
	}
	for (; nodeOne; nodeTwo = nodeOne, nodeOne = nodeOne->express)
	{
		printf("Value checked at index [%d] = [%d]",
			nodeOne->index, nodeOne->n);
		printf("\n");
		if (nodeOne->n >= value || !nodeOne->express)
		{
			if (nodeOne->n < value && !nodeOne->express)
			{
				nodeTwo = nodeOne;
				while (nodeOne->next)
				{
					nodeOne = nodeOne->next;
				}
			}
			printf("Value found between indexes [%d] and [%d]",
				nodeTwo->index, nodeOne->index);
			printf("\n");
			for (; nodeTwo; nodeTwo = nodeTwo->next)
			{
				printf("Value checked at index [%d] = [%d]",
					nodeTwo->index, nodeTwo->n);
				printf("\n");
				if (nodeTwo->n == value)
				{
					return (nodeTwo);
				}
			}
		}
		nodeTwo = nodeOne;
		nodeOne = nodeOne->express;
	}
	return (NULL);
}
