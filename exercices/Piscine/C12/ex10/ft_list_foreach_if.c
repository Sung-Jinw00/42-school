/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:34:21 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 16:34:21 by marvin           ###   ########.fr       */
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
}

void	print(void *data)
{
	printf("%s ", (char *)data);
}
 */
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*cur;

	cur = begin_list;
	while (cur)
	{
		if ((*cmp)(cur->data, data_ref) == 0)
			(*f)(cur->data);
		cur = cur->next;
	}
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
	ft_list_foreach_if(newlist, *print, ref, *ft_strcmp);
} */