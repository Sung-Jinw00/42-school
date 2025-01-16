/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arbres_binaires.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:17:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:17:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree_test.h"
#include <stdio.h>
#include <stdlib.h>

int	len_bt(BinTree *bt)
{
	if (!bt)
		return (0);
	return (1 + len_bt(bt->left) + len_bt(bt->right));
}

int	high_bt(BinTree *bt)
{
	int h1, h2;
	if (!bt)
		return (0);
	h1 = high_bt(bt->left);
	h2 = high_bt(bt->right);
	if (h1 > h2)
		return (1 + h1);
	return (1 + h2);
}

Node	*create_node(int data)
{
	Node	*node;

	node = malloc(sizeof(Node));
	if (!node)
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	print_bt(BinTree *bt)
{
	if (bt)
	{
		print_bt(bt->left);
		printf("%d\n", bt->data);
		print_bt(bt->right);
	}
}

BinTree	*free_bt(BinTree *bt)
{
	if (!bt)
	{
		bt->left = free_bt(bt->left);
		bt->right = free_bt(bt->right);
		free(bt);
	}
	return (NULL);
}

BinTree	*search(BinTree *bt, int data)
{
	while (bt)
	{
		if (bt->data > data)
			bt = bt->left;
		else if (bt->data < data)
			bt = bt->right;
		else
			return (bt);
	}
	return (NULL);
}

BinTree	*insert(BinTree *bt, int data)
{
	BinTree	*prec;
	BinTree	*head;

	prec = NULL;
	head = bt;
	if (!bt)
		return (create_node(data));
	while (bt)
	{
		prec = bt;
		if (bt->data > data)
			bt = bt->left;
		else
			bt = bt->right;
	}
	if (prec->data > data)
		prec->left = create_node(data);
	else
		prec->right = create_node(data);
	return (head);
}

BinTree	*empty_bt(void)
{
	return (NULL);
}

int	main(void)
{
	BinTree	*bt;

	bt = empty_bt();
	bt = insert(bt, 0);
	bt = insert(bt, -5);
	bt = insert(bt, -10);
	bt = insert(bt, -3);
	bt = insert(bt, 5);
	bt = insert(bt, 10);
	bt = insert(bt, 6);
	bt = insert(bt, 8);
	bt = insert(bt, 14);
	print_bt(bt);
	/* printf("-> %d\n", search(bt, 6)->data);
	printf("high = %d\n", high_bt(bt)); */
	printf("len = %d\n", len_bt(bt));
	bt = free_bt(bt);
	return (0);
}
