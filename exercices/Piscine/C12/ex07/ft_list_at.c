/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:57:16 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 17:57:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

unsigned int	len_list(t_list *begin_list)
{
	t_list			*dupl;
	unsigned int	i;

	i = -1;
	dupl = begin_list;
	while (dupl)
	{
		i++;
		dupl = dupl->next;
	}
	return (i);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list)
		return (NULL);
	if (nbr > len_list(begin_list))
		return (NULL);
	while (i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

/* #include <stdio.h>

t_list	*add_elems(t_list *elem, char **strs, int mark, int pos)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*cell;
	int		i;

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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*newlist;
	int		i;

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
	char *strs[6];
	t_list *newlist;

	newlist = malloc(sizeof(t_list) * 6);
	strs[0] = "Hello";
	strs[1] = "Wassup";
	strs[2] = "Hi";
	strs[3] = "Hey";
	strs[4] = "Yeppi";
	strs[5] = NULL;
	newlist = ft_list_push_strs(5, strs);
	newlist = ft_list_at(newlist, 3);
	printf("%s\n", (char *)newlist->data);
} */
