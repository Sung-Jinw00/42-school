/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:49:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/04 15:52:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

/* #include <stdio.h>

void	print_elem(t_list *elem)
{
	t_list	*elem;

	while (elem)
	{
		printf("%s\n", (char *)elem->data);
		elem = elem->next;
	}
} */
t_list	*ft_create_elem(void *data)
{
	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

// print_elem(elem);
/* int main (void)
{
	void *data = "Hello world";
	ft_create_elem(data);
} */