/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:15:43 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/11 19:17:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
/* #include <stdio.h>

void	print_elem(t_list *elem)
{
	while (elem)
	{
		printf("%s\n", (char *)elem->data);
		elem = elem->next;
	}
} */

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = ft_create_elem(data);
	temp->next = *begin_list;
	*begin_list = temp;
}

	//print_elem(*begin_list);
/* int main (void)
{
	t_list	*begin_list;
	void *data;

	data = "Hello";
	begin_list = malloc(sizeof(t_list));
	begin_list->data = "World";
	begin_list->next = NULL;
	ft_list_push_front(&begin_list, data);
} */