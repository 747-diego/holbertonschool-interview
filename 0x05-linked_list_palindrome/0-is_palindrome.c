#include "lists.h"


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the beginning of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *copy = *head;
    listint_t *end = *head;
    listint_t *previous, *tempNode;

    int index = 0;
    int size = 0;
    int palindrome = 1;




    if (!head)
    {
        return (0);
    }
    
    
    while (copy)
    {
        copy = copy->next;
        size++;
    }

    
    if (size == 1 || !*head)
    {
        return(1);
    }

    copy = *head;

    
    while (index < size)
    {
        tempNode = end->next;
        
        
        if (index > size / 2)
        {
            end->next = previous;
        }
        previous = end;
        
        
        if (tempNode)
        {
            end = tempNode;
        }

        index++;
    }

    previous = NULL;



    index = 0;
    while (index < size / 2)
    {
        if (copy->n != end->n)
        {
            palindrome = 0;
        }

        
        
        tempNode = end->next;
        
        end->next = previous;
        previous = end;
        
        end = tempNode;
        copy = copy->next;
        
        
        index++;
    }

    return (palindrome);



    
}
