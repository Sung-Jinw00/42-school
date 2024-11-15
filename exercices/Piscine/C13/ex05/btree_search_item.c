/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:43:27 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 20:43:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/* int	ft_strcmp(void *s1, void *s2)
{
	int a;
	int b;

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

void	*btree_search_item(t_btree *root, void *data_ref, \
int (*cmpf)(void *, void *))
{
	void	*answer;

	answer = NULL;
	if (root)
	{
		if ((cmpf)(root->item, data_ref) == 0)
			return (data_ref);
		else
		{
			answer = btree_search_item(root->left, data_ref, cmpf);
			answer = btree_search_item(root->right, data_ref, cmpf);
		}
	}
	return (answer);
}

/* #include <stdio.h>

void print_btree(t_btree *root)
{
	if (root)
	{
		print_btree(root->left);
		printf("%d\n", *(int *)root->item);
		print_btree(root->right);
	}
}

t_btree *btree_create_at(t_btree *root, void *data)
{
	t_btree *head = root;
	t_btree *prev = root;

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

int main(void)
{
	t_btree *root;
	void *item;
	int val = 3;
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
	void *answer = btree_search_item(root, item, *ft_strcmp);
	if (!answer)
		printf("reponse : (null)");
	else
		printf("reponse : %d\n", *(int *)answer);
} */