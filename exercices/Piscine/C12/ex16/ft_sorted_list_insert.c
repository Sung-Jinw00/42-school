/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:19:55 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 17:19:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h>

void	print_list(t_list *L)
{
	while (L)
	{
		printf("%s ", (char *)L->data);
		L = L->next;
	}
	printf("\n");
}

int	ft_strcmp(void *s1, void *s2)
{
	char *a;
	char *b;
	int i;

	i = -1;
	a = (char *)s1;
	b = (char *)s2;
	while (a[++i] || b[i])
		if (a[i] != b[i])
			return (a[i] - b[i]);
	return (0);
} */

void	big_cmp(t_list **before, t_list **after, int (*cmp)(), t_list *new_cell)
{
	while (*before)
	{
		if (!*after)
		{
			if ((*cmp)(*before, new_cell) >= 0)
			{
				(*before)->next = new_cell;
				return ;
			}
		}
		else if ((*cmp)(new_cell, *after) <= 0
			&& (*cmp)(*before, new_cell) >= 0)
		{
			new_cell->next = *after;
			(*before)->next = new_cell;
			return ;
		}
		*before = (*before)->next;
		*after = (*before)->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*after;
	t_list	*before;
	t_list	*new_cell;

	new_cell = ft_create_elem(data);
	if (!begin_list)
		*begin_list = new_cell;
	before = *begin_list;
	after = before->next;
	if ((*cmp)(before, new_cell) >= 0)
	{
		new_cell->next = before;
		*begin_list = new_cell;
		if (!after)
			return ;
	}
	big_cmp(&before, &after, cmp, new_cell);
}

/* t_list	*add_at(t_list *L, void *data, int pos)
{
	t_list *prec;
	t_list *cur;
	t_list *cell;
	int i;

	i = 0;
	cur = L;
	cell = ft_create_elem(data);
	if (!L)
		return (cell);
	else if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
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

int main (void)
{
	t_list *newlist;
	void *data;
	char *elem = "d";
	data = elem;

	newlist = NULL;
	newlist = add_at(newlist, "a", 0);
	newlist = add_at(newlist, "b", 1);
	newlist = add_at(newlist, "c", 2);
	newlist = add_at(newlist, "e", 3);
	newlist = add_at(newlist, "j", 4);
	newlist = add_at(newlist, "l", 5);
	newlist = add_at(newlist, "v", 6);
	print_list(newlist);
	ft_sorted_list_insert(&newlist, data, *ft_strcmp);
	print_list(newlist);
} */