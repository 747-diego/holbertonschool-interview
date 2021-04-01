#ifndef _LINER_SEARCH_
#define _LINER_SEARCH_



/* HEADER FILES */
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>


/* STRUCTS */
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/* PROTOTYPES */
skiplist_t *linear_skip(skiplist_t *head, int value);

#endif /* _LINER_SEARCH_ */
