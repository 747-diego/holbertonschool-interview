#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

/* HEADER FIKES */
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPES */
void heap_sort(int *array, size_t size);
void swapNode(int *array, int currentNode, int farNode);
int checkLeft(int *array, int farNode, int left, int nodePosition);
int checkRight(int *array, int farNode, int right, int nodePosition);
void sortArray(int *array, int nodePosition, int currentNode, int arrayLength);
void print_array(const int *array, size_t size);

#endif /* __HEAPSORT_H__ */
