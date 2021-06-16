#include "search.h"

/**
 * linear_skip - finds value in a linked list with an express lane
 * @list: pointer to linked list
 * @value: value were searching for
 * Return: NULL or ptr with value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *node = list;
    skiplist_t *temp;
	size_t index = 0;
    size_t tempIndex = 0;
	int totalValue = 0;
    int size = 0;

	while (node)
	{
		index = node->index;
		if (node->express && !totalValue)
		{
			temp = node->express;
			tempIndex = temp->index;
			printf("Value checked at index [%ld] = [%d]\n", tempIndex, temp->n);
			if (temp->n >= value)
			{
				printf("Value found between indexes [%ld] and [%ld]\n", index, tempIndex);
				totalValue = 1;
			}
			else
            {
				node = temp;
            }
		}
		else
		{
			if (totalValue == 0)
			{

                while (node->next)
                {
                    node = node->next;
                    size += 1;
                }
                tempIndex = size;


				printf("Value found between indexes [%ld] and [%ld]\n", index, tempIndex);
				totalValue = 1;
			}
			printf("Value checked at index [%ld] = [%d]\n", index, node->n);
			if (node->n == value)
				return (node);

			node = node->next;
		}
	}
	return (NULL);
}
