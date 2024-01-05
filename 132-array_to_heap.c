#include "binary_trees.h"

/**
 * array_to_heap - function builds a Max Binary Heap tree from an array
 * @array: the input array
 * @size: the size of array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t j = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	while (j < size)
	{
		heap_insert(&root, array[j]);
		j++;
	}
	return (root);
}
