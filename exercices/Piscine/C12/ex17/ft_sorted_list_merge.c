/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:02:14 by marvin            #+#    #+#             */
/*   Updated: 2024/10/11 18:02:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h>

int	ft_strcmp(void *s1, void *s2)
{
	char	*a;
	char	*b;
	int		i;
	t_list	*temp;

	i = -1;
	a = (char *)s1;
	b = (char *)s2;
	while (a[++i] || b[i])
		if (a[i] != b[i])
			return (a[i] - b[i]);
	return (0);
} */
void	ft_swap_list(t_list **pos1, t_list **pos2, t_list **pos3)
{
	temp = NULL;
	if (*pos1 && *pos2 && *pos3)
	{
		temp = *pos2;
		temp->next = (*pos3)->next;
		(*pos1)->next = *pos3;
		(*pos3)->next = temp;
		*pos2 = *pos3;
		*pos3 = temp;
	}
}

void	switch_start(t_list **pos1, t_list **pos2, t_list **pos3, t_list **L)
{
	t_list	*temp1;

	if (*pos1 && *pos2 && *pos3)
	{
		temp1 = *pos1;
		(*pos2)->next = temp1;
		temp1->next = *pos3;
		*pos1 = *pos2;
		*pos2 = temp1;
		*L = *pos1;
	}
	else if (*pos1 && *pos2 && !*pos3)
	{
		temp1 = *pos1;
		(*pos2)->next = temp1;
		temp1->next = NULL;
		*pos1 = *pos2;
		*pos2 = temp1;
		*L = *pos1;
	}
}

void	init(t_list **pos1, t_list **pos2, t_list **pos3, t_list *begin_list)
{
	if (!begin_list)
	{
		*pos1 = (*pos1)->next;
		*pos2 = (*pos1)->next;
		*pos3 = (*pos2)->next;
		return ;
	}
	else
	{
		*pos1 = begin_list;
		*pos2 = (*pos1)->next;
		*pos3 = (*pos2)->next;
		return ;
	}
	begin_list = *pos1;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*pos1;
	t_list	*pos2;
	t_list	*pos3;

	pos1 = *begin_list;
	pos2 = pos1->next;
	pos3 = pos2->next;
	if (!pos1 || !pos2)
		return ;
	else if (((*cmp)(pos1->data, pos2->data) > 0))
		switch_start(&pos1, &pos2, &pos3, begin_list);
	if (!pos3)
		return ;
	while (pos3)
	{
		if ((*cmp)(pos2->data, pos3->data) > 0)
		{
			ft_swap_list(&pos1, &pos2, &pos3);
			init(&pos1, &pos2, &pos3, *begin_list);
			if (((*cmp)(pos1->data, pos2->data) > 0))
				switch_start(&pos1, &pos2, &pos3, begin_list);
		}
		else
			init(&pos1, &pos2, &pos3, 0);
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*cur;

	if (!begin_list1 || !begin_list2)
		return ;
	cur = *begin_list1;
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
	ft_list_sort(begin_list1, cmp);
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
	newlist1 = add_at(newlist1, "a", 0);
	newlist1 = add_at(newlist1, "c", 1);
	newlist1 = add_at(newlist1, "d", 2);
	newlist1 = add_at(newlist1, "f", 3);
	newlist1 = add_at(newlist1, "j", 4);
	newlist1 = add_at(newlist1, "k", 5);
	newlist1 = add_at(newlist1, "m", 6);

	newlist2 = NULL;
	newlist2 = add_at(newlist2, "n", 0);
	newlist2 = add_at(newlist2, "l", 1);
	newlist2 = add_at(newlist2, "i", 2);
	newlist2 = add_at(newlist2, "h", 3);
	newlist2 = add_at(newlist2, "g", 4);
	newlist2 = add_at(newlist2, "e", 5);
	newlist2 = add_at(newlist2, "b", 6);
	printf("list 1 : ");
	print_list(newlist1);
	printf("list 2 : ");
	print_list(newlist2);
	ft_sorted_list_merge(&newlist1, newlist2, *ft_strcmp);
	printf("merged list : ");
	print_list(newlist1);
} */