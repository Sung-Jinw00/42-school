/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:32:13 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 17:32:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
/* #include <stdio.h>
		printf("%s\n", (char *)begin_list->data); */

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;

	temp = NULL;
	while (begin_list)
	{
		temp = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = temp;
	}
}

/* void	free_fct(void *data)
{
	free(data);
}

t_list *add_elems(t_list *elem, char **strs, int mark, int pos)
{
	t_list *cur;
	t_list *prev;
	t_list *cell;
	int i;

	i = 1;
	cur = elem;
	cell = ft_create_elem(strs[mark]);
	if (!elem)
	{
		elem->data = strs[pos];
		return (elem);
	}
	while (i <= pos)
	{
		prev = cur;
		cur = cur->next;
		i++;
	}
	prev->next = cell;
	return (elem);
} 

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list *newlist;
	int i;

	i = 1;
	newlist = ft_create_elem(strs[size - 1]);
	size--;
	while (size - 1 >= 0)
	{
		newlist = add_elems(newlist, strs, size - 1, i);
		size--;
		i++;
	}
	return (newlist);
}

int main (void)
{
	char *strs[4];
	t_list *newlist;

	newlist = malloc(sizeof(t_list) * 3);
	strs[0] = "Hello";
	strs[1] = "Wassup";
	strs[2] = "Hi";
	strs[3] = NULL;
	newlist = ft_list_push_strs(3, strs);
	ft_list_clear(newlist, &free_fct);
} */