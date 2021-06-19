#include "lists.h"


/**
 * find_listint_loop - Finds the start of a loop in a linked list
 * @head: The start of the linked list
 * Return: The node where a loop starts, otherwise Null
 */
listint_t *find_listint_loop(listint_t *head)
{

	listint_t *firstNode = head;
	listint_t *secondNode = head;

	while (secondNode && secondNode->next)
	{
		firstNode = firstNode->next;
		secondNode = secondNode->next->next;
		if (firstNode == secondNode)
		{
			firstNode = head;
			while (firstNode != secondNode)
			{
				firstNode = firstNode->next;
				secondNode = secondNode->next;
			}
			return (firstNode);
		}
	}
	return (NULL);
}
