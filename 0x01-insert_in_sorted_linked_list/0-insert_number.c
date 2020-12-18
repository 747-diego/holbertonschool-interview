#include "lists.h"


/**
 * insert_node - function in C that inserts a number into a sorted singly linked list.
 * @head: double pointer point at the begining of the list
 * @number: content of what number goes inside the NEW NODE
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *currentNode = *head;
	listint_t *newNode = malloc(sizeof(listint_t));

    /* If the NEW NODE doesnt exist, return NULL */
	if (!newNode)
		return (NULL);


	newNode->n = number;
    newNode->next = NULL;

    /* If the HEAD pointer doesnt exist, set the NEW NODE pointer-next to the HEAD pointer */
    /* and then set the HEAD pointer to the NEW NODE */
	if (!*head)
	{

		newNode->next = *head;
		*head = newNode;

	}

    /* OTHERWISE */
	else
	{

        /* While the content of the CURRENT NODE is less than the content of the NEW NODE */
        /* and if the CURRENT NODE pointer-next exists, then set the CURRENT NODE to pointer-next */
		while (currentNode->next->n < newNode->n && currentNode->next)
		{

			currentNode = currentNode->next;

		}

        /* set the NEW NODE pointer-next to CURRENT NODES pointer-next */
        /* and set the CURRENT NODES pointer-next to the NEW NODE and then RETURN the NEW NODE */
		newNode->next = currentNode->next;
		currentNode->next = newNode;

	}

	return (newNode);
}
