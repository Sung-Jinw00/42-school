/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postfix.c                             :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:02:03 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 20:02:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* void	applyf(void *item)
{
	*(int *)item += 3;
} */
void	btree_apply_postfix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		btree_apply_postfix(root->left, applyf);
		btree_apply_postfix(root->right, applyf);
		(*applyf)(root->item);
	}
}

/* #include <stdio.h>

void	print_btree(t_btree *root)
{
	if (root)
	{
		print_btree(root->left);
		print_btree(root->right);
		printf("%d\n", *(int *)root->item);
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
	btree_apply_postfix(root, applyf);
	print_btree(root);
} */