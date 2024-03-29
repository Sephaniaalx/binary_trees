#include "binary_trees.h"
#include<stdlib.h>

/**
 * swap - this swaps two nodes in binary tree
 * @a: the first node
 * @b: the second node
 * Return: pointer to root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t a_copy = INIT_NODE;

	a_copy.n = a->n;
	a_copy.parent = a->parent;
	a_copy.left = a->left;
	a_copy.right = a->right;
	a->parent = b;
	a->left = b->left;
	a->right = b->right;
	if (b->left)
		b->left->parent = a;
	if (b->right)
		b->right->parent = a;

	b->parent = a_copy.parent;
	if (a_copy.parent)
	{
		if (a == a_copy.parent->left)
			a_copy.parent->left = b;
		else
			a_copy.parent->right = b;
	}
	if (b == a_copy.left)
	{
		b->left = a;
		b->right = a_copy.right;
		if (a_copy.right)
			a_copy.right->parent = b;
	}
	else if (b == a_copy.right)
	{
		b->right = a;
		b->left = a_copy.left;
		if (a_copy.left)
			a_copy.left->parent = b;
	}
	while (b->parent)
		b = b->parent;
	return (b);
}

/**
 * convert - this converts number and base into string
 * @num: the input number
 * @base: the input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *p;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buffer[49];
	*p = 0;
	do {
		*--p = rep[num % base];
		num /= base;
	} while (num);

	return (p);
}

/**
 * binary_tree_size - this measures the size of a binary tree
 * @tree: the input binary tree
 * Return: number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * insert - the helper function to insert node to correct location
 * @root: the double pointer to root of max heap
 * @node: node to insert
 */
void insert(heap_t **root, heap_t *node)
{
	heap_t *temp;
	int size;
	unsigned int i;
	char *binary;
	char c;

	temp = *root;
	size = binary_tree_size(temp) + 1;
	binary = convert(size, 2, 1);
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				node->parent = temp;
				temp->right = node;
				break;
			}
			else if (c == '0')
			{
				node->parent = temp;
				temp->left = node;
				break;
			}
		}
		if (c == '1')
			temp = temp->right;
		else if (c == '0')
			temp = temp->left;
	}
}


/**
 * heap_insert - this inserts a value in Max Binary Heap
 * @root: a double pointer to root of tree
 * @value: the input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *i = NULL, *ret;

	if (!root)
		return (NULL);
	i = calloc(1, sizeof(heap_t));
	i->n = value;
	if (!*root)
	{
		*root = i;
		return (i);
	}
	insert(root, i);
	while (i->parent && i->n > i->parent->n)
	{
		ret = swap(i->parent, i);
		if (ret)
			*root = ret;
	}
	return (i);
}
