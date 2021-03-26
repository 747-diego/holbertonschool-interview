#ifndef _ARRAY_TO_AVL_H
#define _ARRAY_TO_AVL_H

/* HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

/* TYPE STRUCTS */
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* PROTOTYPES */
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *treeNode(int *array, size_t size);
binary_tree_t *newNode(int value, binary_tree_t *parent);
void binary_tree_print(const binary_tree_t *tree);

#endif
