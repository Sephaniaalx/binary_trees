#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - function checks if a node is a leaf
 * @node: the pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - function measures the height of a binary tree
 * @tree: the pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - function checks if a binary tree is perfect
 * @tree: the pointer to the root node of the tree to check
 *
 * Return: returns 1 if perfect, 0 if otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *i, *r;

	if (tree == NULL)
		return (1);
	i = tree->left;
	r = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (i == NULL || r == NULL)
		return (0);
	if (binary_tree_height(i) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(i) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  function checks if a binary tree is complete
 * @tree: the pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	l_height = binary_tree_height(l);
	r_height = binary_tree_height(r);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
