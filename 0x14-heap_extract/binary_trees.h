#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/* HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

/* STRUCTS */
typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;

/* PROTOTYPES */
int heap_extract(heap_t **root);
void swap(heap_t *firstNode, heap_t *secondNode);
int check(int left, int right);
int findSize(heap_t *firstNode, int length);
void checkLeft(heap_t *firstNode, int shiftLeft, int length, int lengthSum);
void checkRight(heap_t *firstNode, int shiftRight, int length, int lengthSum);

#endif /* _BINARY_TREES_H_ */
