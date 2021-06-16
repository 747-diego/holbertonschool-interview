#include "search.h"

/**
 * linear_skip - finds value in a linked list with an express lane
 * @list: pointer to linked list
 * @value: value were searching for
 * Return: NULL or ptr with value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	char check[] = "Value checked at index [%ld] = [%d]\n";
	char between[] = "Value found between indexes [%ld] and [%ld]\n";
	skiplist_t *temp, *head = list, *node = list;
	size_t index = 0, tempIndex = 0;
	int totalValue = 0, size = 0;

	while (node)
	{
		index = node->index;
		if (node->express && !totalValue)
		{
			temp = node->express;
			tempIndex = temp->index;
			printf("%s",check, tempIndex, temp->n);
			if (temp->n >= value)
			{
				printf("%s",between, index, tempIndex);
				totalValue = 1;
			}
			else
				node = temp;
		}
		else
		{
			if (totalValue == 0)
			{
				while (head->next)
				{
					head = head->next;
					size += 1;
				}
				tempIndex = size;
				printf("%s",between, index, tempIndex);
				totalValue = 1;
			}
			printf("%s",check, index, node->n);
			if (node->n == value)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}
