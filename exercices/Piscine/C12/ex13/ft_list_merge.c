/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:55:06 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 18:55:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h> */

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	cur = *begin_list1;
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
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
	t_list *newlist1;
	t_list *newlist2;

	newlist1 = NULL;
	newlist1 = add_at(newlist1, "those", 0);
	newlist1 = add_at(newlist1, "exercices", 1);
	newlist1 = add_at(newlist1, "will", 2);

	newlist2 = NULL;
	newlist2 = add_at(newlist2, "never", 0);
	newlist2 = add_at(newlist2, "ever", 1);
	newlist2 = add_at(newlist2, "ended!", 2);
	printf("list 1 : ");
	print_list(newlist1);
	printf("list 2 : ");
	print_list(newlist2);
	ft_list_merge(&newlist1, newlist2);
	printf("merged list : ");
	print_list(newlist1);
} */