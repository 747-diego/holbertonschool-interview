#include "lists.h"

/**
 * checkLoop - checks if temp node is equal to node ahead
 * @nodeone: the temp node
 * @nodetwo: the second tempnode
 * Return: node
 */
listint_t checkLoop(listint_t *nodeone, listint_t *nodetwo)
{


    while (nodeone != nodetwo)
    {
        nodeone = nodeone->next;
        nodetwo = nodetwo->next;
    }
    return (*nodeone);


}

/**
 * find_listint_loop -  finds the loop in a linked list.
 * @head: beginning of list
 * Return: The address of the node where loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tempOne = head;
	listint_t *tempTwo = head;


	while (tempTwo && tempTwo->next)
	{


		tempOne = tempOne->next;
		tempTwo = tempTwo->next->next;


		if (tempOne == tempTwo)
		{

			tempOne = head;
			checkLoop(tempOne, tempTwo);
			return (0);

		}
	}

	return (NULL);

}

