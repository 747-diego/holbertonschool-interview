#include "list.h"

/**
 * add_node_end - brings a temp node to the finish
 * @list: array
 * @str: name
 * Return: new node
 */
List *add_node_end(List **list, char *str)
{
	List *endingNode, *temp;


	temp = malloc(sizeof(List));
	if (temp == NULL)
	{
		return (NULL);
	}

	if (list == NULL)
	{
		return (NULL);
	}

	temp->str = strdup((const char *) str);
	if (temp->str == NULL)
	{
		free(temp);
		return (NULL);
	}

	endingNode = *list;
	if (endingNode == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		*list = temp;
		return (temp);
	}
	endingNode->prev->next = temp;

	temp->prev = endingNode->prev;

	temp->next = endingNode;

	endingNode->prev = temp;

	return (temp);
}


/**
 * add_node_begin - brings a temp node to the start
 * @list: array
 * @str: name
 * Return: new node
 */
List *add_node_begin(List **list, char *str)
{
	List *startingNode, *temp;


	temp = malloc(sizeof(List));
	if (temp == NULL)
	{
		return (NULL);
	}

	if (list == NULL)
	{
		return (NULL);
	}

	temp->str = strdup((const char *) str);
	if (temp->str == NULL)
	{
		free(temp);
		return (NULL);
	}

	startingNode = *list;
	if (startingNode == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		*list = temp;
		return (temp);
	}

	startingNode->prev->next = temp;

	temp->prev = startingNode->prev;

	temp->next = startingNode;

	startingNode->prev = temp;

	*list = temp;
	return (temp);
}
