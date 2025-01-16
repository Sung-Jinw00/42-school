/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:47:47 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 18:47:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*newnode;

	newnode = malloc(sizeof(t_btree));
	newnode->item = item;
	newnode->left = NULL;
	newnode->right = NULL;
	return (newnode);
}

/* #include <stdio.h>

int	main(void)
{
	t_btree *new_btree;
	int i = 1;

	new_btree = btree_create_node(&i);
	printf("%d\n", *(int *)new_btree->item);
} */