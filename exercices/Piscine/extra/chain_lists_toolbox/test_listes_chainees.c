/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Listes_chainees.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:17:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:17:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liste_test.h"
#include <stdio.h>
#include <stdlib.h>

long	len_list(List *L)
{
	long	len;

	len = 0;
	while (L)
	{
		len++;
		L = L->next;
	}
	return (len);
}

int	is_empty_list(List *L)
{
	return (L == NULL);
}

Cell	*create_cell(int data)
{
	Cell	*cell;

	cell = malloc(sizeof(Cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
}

void	print_list(List *L)
{
	while (L)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

List	*free_list(List *L)
{
	List	*tmp;

	tmp = NULL;
	while (L)
	{
		tmp = L->next;
		free(L);
		L = tmp;
	}
}

List	*free_at(List *L, int pos)
{
	List	*prec;
	List	*cur;
	int		i;

	cur = L;
	if (!L)
		return (NULL);
	else if (pos == 0)
	{
		L = L->next;
		free(cur);
		return (L);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (L);
}

void	set_at(List *L, int data, int pos)
{
	int	i;

	i = 0;
	if (!L)
	{
		printf("liste vide\n");
		return ;
	}
	else if (pos > len_list(L))
	{
		printf("position invalide\n");
		return ;
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	L->data = data;
}

int	get_at(List *L, int pos)
{
	int	i;

	i = 0;
	if (!L)
	{
		printf("liste vide\n");
		return (-1);
	}
	else if (pos > len_list(L))
	{
		printf("position invalide\n");
		return (-1);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}

List	*add_at(List *L, int data, int pos)
{
	List	*prec;
	List	*cur;
	int		i;
	Cell	*cell;

	cur = L;
	cell = create_cell(data);
	if (!L)
		return (cell);
	else if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (L);
}

List	*empty_list(void)
{
	return (NULL);
}

int	main(void)
{
	List	*list;

	list = empty_list();
	list = add_at(list, 666, 0);
	print_list(list);
	list = add_at(list, 999, 0);
	print_list(list);
	list = add_at(list, 500, 1);
	print_list(list);
	list = add_at(list, 200, 3);
	print_list(list);
	set_at(list, 1000, 2);
	print_list(list);
	list = free_at(list, 1);
	print_list(list);
	list = free_list(list);
	return (0);
}
