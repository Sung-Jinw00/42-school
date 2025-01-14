/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 17:06:28 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pos_of_value_for_b2(t_list **a_list, t_list *b_list, int bigger_nb)
{
	int		pos;
	t_list	*tmp;

	tmp = *a_list;
	while (tmp)
	{
		if (tmp->data > b_list->data && tmp->data < bigger_nb)
			bigger_nb = tmp->data;
		tmp = tmp->next;
	}
	tmp = *a_list;
	pos = 0;
	while (tmp->data != bigger_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	*a_list = r_or_rr(a_list, len_list(*a_list), pos, 'a');
	return (*a_list);
}

void	init_sort_a(t_list *a_list, t_list **v1, t_list **v2, t_list **v3)
{
	*v1 = a_list;
	*v2 = (*v1)->next;
	*v3 = (*v2)->next;
}

void	sort_a(t_list **a_list)
{
	t_list	*v1;
	t_list	*v2;
	t_list	*v3;

	init_sort_a(*a_list, &v1, &v2, &v3);
	if (!sorted_list_grow(*a_list))
	{
		if (v1->data > v2->data && v2->data < v3->data
			&& !(v1->data == find_max(a_list) && v2->data == find_min(a_list)))
			sa_sb(a_list, 'a');
		else if (v1->data < v2->data && v2->data > v3->data
			&& !(v2->data == find_max(a_list) && v3->data == find_min(a_list)))
		{
			ra_rb(a_list, 'a');
			sa_sb(a_list, 'a');
		}
		else
			sa_sb(a_list, 'a');
		init_sort_a(*a_list, &v1, &v2, &v3);
	}
}

int	get_at(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (!L || (pos > len_list(L)))
		return (-1);
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}

void	final_moves(t_list **a_list, int smaller_nb)
{
	int		pos;
	t_list	*tmp;

	tmp = *a_list;
	pos = 0;
	while (tmp->data != smaller_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	r_or_rr(a_list, len_list(*a_list), pos, 'a');
}
