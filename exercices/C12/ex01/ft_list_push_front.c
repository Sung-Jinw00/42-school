/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:15:43 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/19 12:49:18 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = malloc(sizeof (t_list) * 2);
	elem->data = begin_list[0];
	elem->next = begin_list[1];
	elem->next->data = data;
	elem->next->next = 0;
	//printf("data : %d\nnext : %ls\n", *(int *)elem[0].data, (int *)elem[0].next);
	return (elem);
}

int main(void)
{
	void *data[1];
	int		i[1] = {12};
	
	data[0] = i;
	ft_create_elem(data);
	return (0);
}