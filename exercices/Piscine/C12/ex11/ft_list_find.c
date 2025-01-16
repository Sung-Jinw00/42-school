/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:53:20 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 16:53:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h>

int	ft_strcmp(void *s1, void *s2)
{
	int	result;

	result = 0;
		if (s1 != s2)
		{
			result = s1 - s2;
			return (result);
		}
	return (result);
} */
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}

/* void	print_list(t_list *L)
{
	while (L)
	{
		printf("%s ", (char *)L->data);
		L = L->next;
	}
	printf("\n");
}

t_list	*add_at(t_list *L, void *data, int pos)
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

void	print_elem(t_list *L)
{
	printf("%s", (char *)L->data);
}

int main (void)
{
	t_list *newlist;
	void *ref;
	char *yes = "yeah";
	ref = yes;

	newlist = NULL;
	newlist = add_at(newlist, "oh", 0);
	newlist = add_at(newlist, "yeah", 1);
	newlist = add_at(newlist, "more...", 2);
	print_list(newlist);
	newlist = ft_list_find(newlist, ref, *ft_strcmp);
	print_elem(newlist);
} */