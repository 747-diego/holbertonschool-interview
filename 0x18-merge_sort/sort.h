#ifndef _SPRC_
#define _SPRC_

/* HEADER FILES */
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPES */
void displayNodes(int array[], size_t headNode, size_t tailNode);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void nodeSwap(int array[], size_t headNode, size_t bodyNode,
	size_t nodeTail, int currentArray[]);
void split(int currentNode[], size_t headNode, size_t tailNode, int array[]);

#endif
