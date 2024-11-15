/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:18:37 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 16:18:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

/* #include <stdio.h>
#include <stdlib.h>

int main (void)
{
	t_list	*begin_list;
	t_list *prev;

	begin_list = malloc(sizeof(t_list));
	prev = begin_list;
	begin_list->data = "Hello";
	begin_list->next = malloc(sizeof(t_list));
	begin_list = begin_list->next;
	begin_list->data = "World";
	begin_list = prev;
	begin_list = ft_list_last(begin_list);
	printf("%s\n", (char *)begin_list->data);
} */