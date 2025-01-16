/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:51:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 22:51:53 by marvin           ###   ########.fr       */
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

int	ft_list_size(t_list *begin_list)
{
	int	len;
	int	mid;
	int	len;
	int	len_copy;

	len = 0;
	while (begin_list)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
} */
void	ft_fun2(t_list **begin_list, t_list *last, t_list *first, void *temp)
{
	first = *begin_list;
	len = ft_list_size(*begin_list) - 1;
	len_copy = len;
	mid = len / 2;
	while (len > mid)
	{
		last = *begin_list;
		while (len_copy--)
			last = last->next;
		temp = last->data;
		last->data = first->data;
		first->data = temp;
		len = len - 1;
		len_copy = len;
		first = first->next;
	}
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*last;
	t_list	*first;
	void	*temp;

	last = NULL;
	first = NULL;
	temp = NULL;
	ft_fun2(&begin_list, last, first, temp);
}

/* t_list	*add_at(t_list *L, void *data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	t_list	*cell;
	int		i;

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
	newlist = add_at(newlist, "bout", 0);
	newlist = add_at(newlist, "le", 1);
	newlist = add_at(newlist, "voir", 2);
	newlist = add_at(newlist, "en", 3);
	newlist = add_at(newlist, "a", 4);
	newlist = add_at(newlist, "commence", 5);
	newlist = add_at(newlist, "je", 6);
	print_list(newlist);
	ft_list_reverse_fun(newlist);
	print_list(newlist);
} */