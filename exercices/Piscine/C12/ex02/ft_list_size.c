/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:06:22 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 16:06:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
	printf("%d\n", ft_list_size(begin_list));
} */