/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:39:42 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 18:53:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* void	applyf(void *item, int current_level, int is_first_elem)
{
	int		i;
	t_btree	*prev;

	i = *(int *)item + current_level + is_first_elem;
	i = 0 * i;
} */
void	apply_recursivity(t_btree *root, int cur_lvl, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_btree	*prev;

	prev = root;
	if (root)
	{
		root = root->left;
		if (root)
			(*applyf)(root->item, cur_lvl, 1);
		root = prev;
		root = root->right;
		if (root)
			(*applyf)(root->item, cur_lvl, 0);
		root = prev;
		apply_recursivity(root->left, cur_lvl++, applyf);
		apply_recursivity(root->right, cur_lvl++, applyf);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int	cur_lvl;

	cur_lvl = 0;
	if (root)
		(*applyf)(root->item, cur_lvl, 1);
	apply_recursivity(root, cur_lvl++, applyf);
}

/* #include <stdio.h>

void	print_btree(t_btree *root)
{
	if (root)
	{
		printf("%d\n", *(int *)root->item);
		print_btree(root->left);
		print_btree(root->right);
	}
}

t_btree	*btree_create_at(t_btree *root, void *data)
{
	t_btree	*head;
	t_btree	*prev;

	head = root;
	prev = root;
	if (!root)
		return (btree_create_node(data));
	while (root)
	{
		prev = root;
		if (*(int *)data < *(int *)root->item)
			root = root->left;
		else
			root = root->right;
	}
	if (*(int *)data < *(int *)prev->item)
		prev->left = btree_create_node(data);
	else
		prev->right = btree_create_node(data);
	return (head);
}

#include <string.h>

int	main(void)
{
	t_btree *root;

	root = NULL;
	int i = 0;
	root = btree_create_at(root, &i);
	int j = -4;
	root = btree_create_at(root, &j);
	int l = -10;
	root = btree_create_at(root, &l);
	int m = -7;
	root = btree_create_at(root, &m);
	int n = -2;
	root = btree_create_at(root, &n);
	int o = 3;
	root = btree_create_at(root, &o);
	int p = 8;
	root = btree_create_at(root, &p);
	int q = 5;
	root = btree_create_at(root, &q);
	int r = 14;
	root = btree_create_at(root, &r);
	print_btree(root);
	printf("\n");
	btree_apply_by_level(root, *applyf);
} */