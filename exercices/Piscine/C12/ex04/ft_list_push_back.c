/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:25:47 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 16:25:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/* #include <stdio.h>

void	print_elem(t_list *elem)
{
	t_list	*last;
	t_list	*begin;

	while (elem)
	{
		printf("%s\n", (char *)elem->data);
		elem = elem->next;
	}
}  */
t_list	*add_elem(t_list *elem, void *data)
{
	begin = elem;
	while (elem->next)
		elem = elem->next;
	last = ft_create_elem(data);
	elem->next = last;
	elem = begin;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	*begin_list = add_elem(*begin_list, data);
}

/* #include <stdlib.h>
	print_elem(*begin_list);

int main (void)
{
	t_list	*begin_list;
	t_list *prev;
	void *data;

	data = ":3";
	begin_list = malloc(sizeof(t_list));
	prev = begin_list;
	begin_list->data = "Hello";
	begin_list->next = malloc(sizeof(t_list));
	begin_list = begin_list->next;
	begin_list->data = "World";
	begin_list = prev;
	ft_list_push_back(&begin_list, data);
} */