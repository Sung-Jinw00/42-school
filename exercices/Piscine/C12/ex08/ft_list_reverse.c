/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:30:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 18:30:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h>

void	print_list(t_list *L)
{
	int	i;

	while (L)
	{
		printf("%s ", (char *)L->data);
		L = L->next;
	}
	printf("\n");
} */
t_list	*lastelem(t_list *L, int size)
{
	i = 0;
	while (i < size)
	{
		i++;
		L = L->next;
	}
	return (L);
}

int	ft_list_size(t_list *begin_list)
{
	int	len;

	len = 0;
	while (begin_list)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*copy;
	t_list	*cur;
	int		len;

	len = ft_list_size(*begin_list) - 1;
	copy = *begin_list;
	*begin_list = lastelem(copy, len);
	cur = *begin_list;
	while (len > 0)
	{
		len--;
		cur->next = lastelem(copy, len);
		cur = cur->next;
	}
	cur->next = NULL;
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
	newlist = add_at(newlist, "Hi", 0);
	newlist = add_at(newlist, "Hello", 1);
	newlist = add_at(newlist, "Hey", 2);
	newlist = add_at(newlist, "Wassup", 3);
	newlist = add_at(newlist, "Yas", 4);
	print_list(newlist);
	//write(1, "Ca passe ?", 10);
	ft_list_reverse(&newlist);
	print_list(newlist);
} */
