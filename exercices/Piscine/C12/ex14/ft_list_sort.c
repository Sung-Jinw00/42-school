/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:05:10 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 19:05:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <unistd.h>

void	print_list(t_list *L)
{
	while (L)
	{
		printf("%s ", (char *)L->data);
		L = L->next;
	}
	printf("\n");
}

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

void	switch_start(t_list **pos1, t_list **pos2, t_list **pos3,
		t_list **begin_list)
{
	t_list	*temp1;

	if (*pos1 && *pos2 && *pos3)
	{
		temp1 = *pos1;
		(*pos2)->next = temp1;
		temp1->next = *pos3;
		*pos1 = *pos2;
		*pos2 = temp1;
		*begin_list = *pos1;
	}
	else if (*pos1 && *pos2 && !*pos3)
	{
		temp1 = *pos1;
		(*pos2)->next = temp1;
		temp1->next = NULL;
		*pos1 = *pos2;
		*pos2 = temp1;
		*begin_list = *pos1;
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

/* t_list	*add_at(t_list *L, void *data, int pos)
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

	newlist = NULL;
	newlist = add_at(newlist, "bout", 0);
	newlist = add_at(newlist, "le", 1);
	newlist = add_at(newlist, "voir", 2);
	newlist = add_at(newlist, "en", 3);
	newlist = add_at(newlist, "a", 4);
	newlist = add_at(newlist, "commence", 5);
	newlist = add_at(newlist, "je", 6);
	print_list(newlist);
	ft_list_sort(&newlist, *ft_strcmp);
	print_list(newlist);
} */