#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: returns a pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	temp = pivot->right;
	pivot->right = tree;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pivot;
		else
			temp->right = pivot;
	}

	return (pivot);
}
