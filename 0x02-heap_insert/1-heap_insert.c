#include "binary_trees.h"

/**
 * PlacingNode - places node in list
 * @headNode: beginning of list
 * @size: size
 * @maxSize: max size
 * Return: node
 */
binary_tree_t *PlacingNode(binary_tree_t *headNode, int size, int maxSize)
{
	binary_tree_t *FirstNode, *SecondNode;
	int posSize = size + 1;

	if ((headNode->left) && !(headNode->right))
	{
		return (headNode);
	}
	if (!(headNode->right || headNode->left))
	{
		if (size == maxSize)
		{
			return (NULL);
		}
		else
		{
			return (headNode);
		}
	}
	FirstNode = PlacingNode(headNode->left, posSize, maxSize);
	SecondNode = PlacingNode(headNode->right, posSize, maxSize);
	if (FirstNode)
	{
		return (FirstNode);
	}
	else
	{
		return (SecondNode);
	}
}

/**
 * swap - chmod 777 -> node
 * @NodeSwapOne: swapping permissions on the first node
 * @NodeSwapTwo: swapping permissions on the second node
 */
void swap(binary_tree_t *NodeSwapOne, binary_tree_t *NodeSwapTwo)
{
	binary_tree_t *node;

	node = NodeSwapTwo->parent;
	NodeSwapTwo->parent = NodeSwapOne->parent;
	NodeSwapOne->parent = node;
	node = NodeSwapTwo->left;
	NodeSwapTwo->left = NodeSwapOne->left;
	NodeSwapOne->left = node;
	node = NodeSwapTwo->right;
	NodeSwapTwo->right = NodeSwapOne->right;
	NodeSwapOne->right = node;
}


/**
 * swap - object swap
 * @obj: object
 * @parent: parent
 */
void swap(binary_tree_t *obj, binary_tree_t *parent)
{
	swap(obj, parent);
	parent->parent = obj;
	if (obj->left == obj)
	{
		obj->left = parent;
		if (obj->right)
			obj->right->parent = obj;
	}
	if (obj->right == obj)
	{
		obj->right = parent;
		if (obj->left)
			obj->left->parent = obj;
	}
	if (obj->parent)
	{
		if (obj->parent->left == parent)
		{
			obj->parent->left = obj;
		}
		if (obj->parent->right == parent)
		{
			obj->parent->right = obj;
		}
	}
	if (parent->left)
	{
		if (parent->left->parent == obj)
		{
			parent->left->parent = parent;
		}
	}
	if (parent->right)
	{
		if (parent->right->parent == obj)
		{
			parent->right->parent = parent;
		}
	}
}

/**
 * heap_insert - max binary heap
 * @root: pointer to root
 * @value: stored content
 * Return: new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *placeNode, *substitute, *nodeOne, *nodeTwo;
	int holder = 0;

	if (!root)
		return (NULL);
	nodeOne = binary_tree_node(NULL, value);
	if (nodeOne == NULL)
		return (NULL);
	if (!(*root))
	{
		*root = nodeOne;
		return (nodeOne);
	}
	substitute = *root;
	while (substitute->left)
	{
		substitute = substitute->left;
		holder += 1;
	}
	placeNode = PlacingNode(*root, 0, holder);
	if (!placeNode)
	{
		placeNode = *root;
		while (placeNode->left)
			placeNode = placeNode->left;
	}
	if (placeNode->left)
		placeNode->right = nodeOne;
	else
		placeNode->left = nodeOne;
	nodeOne->parent = placeNode;
	nodeTwo = nodeOne;
	while (nodeTwo->parent && nodeTwo->n > nodeTwo->parent->n)
		swap(nodeTwo, nodeTwo->parent);
	while (nodeTwo->parent)
		nodeTwo = nodeTwo->parent;
	*root = ((heap_t *)nodeTwo);
	return (nodeTwo);
}
