#ifndef _LISTS_H_
#define _LISTS_H_

/* HEADER FILES */
#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* PROTOTYPES */
listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t findLoop(listint_t *numOne, listint_t *numTwo);
listint_t *find_listint_loop(listint_t *head);


#endif
