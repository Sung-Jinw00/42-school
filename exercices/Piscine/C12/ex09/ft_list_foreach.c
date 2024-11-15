/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:49:06 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 23:49:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h>

void	modif(void *data)
{
	printf("%s ", (char *)data);
} */

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*cur;

	cur = begin_list;
	while (cur)
	{
		(*f)(cur->data);
		cur = cur->next;
	}
}

/* void	print_list(t_list *L)
{
	while (L)
	{
		printf("%s ", (char *)L->data);
		L = L->next;
	}
	printf("\n");
}

t_list	*add_at(t_list *L, void *data, int pos)
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

	newlist = NULL;
	newlist = add_at(newlist, "Sauvez", 0);
	newlist = add_at(newlist, "moi", 1);
	newlist = add_at(newlist, "bordel", 2);
	print_list(newlist);
	ft_list_foreach(newlist, *modif);
} */