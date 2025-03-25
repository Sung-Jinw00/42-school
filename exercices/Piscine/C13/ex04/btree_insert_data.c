/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:02:03 by marvin            #+#    #+#             */
/*   Updated: 2025/03/23 17:49:25 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* int	ft_strcmp(void *s1, void *s2)
{
	int	a;
	int	b;

	if (!s1)
		a = 0;
	else
		a = *(int *)s1;
	if (!s2)
		b = 0;
	else
		b = *(int *)s2;
	return (a - b);
} */
void	left(t_btree **root, t_btree **prev, void *item, int (*cmpf)(void *,
			void *))
{
	*root = (*root)->left;
	while (*root)
	{
		*prev = *root;
		if ((cmpf)(item, (*root)->item) < 0)
			*root = (*root)->left;
		else
			*root = (*root)->right;
	}
}

void	right(t_btree **root, t_btree **prev, void *item, int (*cmpf)(void *,
			void *))
{
	*root = (*root)->right;
	while (*root)
	{
		*prev = *root;
		if ((cmpf)(item, (*root)->item) < 0)
			*root = (*root)->left;
		else
			*root = (*root)->right;
	}
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	t_btree	*head;
	t_btree	*prev;

	head = *root;
	prev = *root;
	if (!*root)
		head = btree_create_node(item);
	else if ((cmpf)(item, 0) < 0)
		left(root, &prev, item, cmpf);
	else
		right(root, &prev, item, cmpf);
	if ((cmpf)(item, prev->item) < 0)
		prev->left = btree_create_node(item);
	else
		prev->right = btree_create_node(item);
	*root = head;
}

/* #include <stdio.h>

void	print_btree(t_btree *root)
{
	if (root)
	{
		print_btree(root->left);
		printf("%d\n", *(int *)root->item);
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
	void *item;
	int val = 12;
	item = &val;

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
	printf("\ndata ref : %d\n", *(int *)item);
	printf("\n");
	btree_insert_data(&root, item, *ft_strcmp);
	print_btree(root);
} */