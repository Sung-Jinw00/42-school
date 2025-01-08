/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:26 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/08 21:33:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_a_list(t_list **a_list, t_list **b_list, int chunk)
{
	int pos;

	pos = 0;
	while (*b_list && chunk > 0)
	{
		while (*b_list && (*b_list)->chunk_level == chunk)
		{
			pos = pos_of_highest_value_in_chunk(*b_list, chunk);
			if (pos != 0)
			{
				while (pos > 0)
				{
					ra_rb(b_list, 'b');
					pos--;
				}
			}
			pa_pb(a_list, b_list, 'a');
		}
		chunk--;
	}
}

void	sort_by_chunk(t_list **a_list, t_list **b_list, int max_chunk)
{
	int 	index;
	int		fst_chunk;
	int		sec_chunk;

	index = 0;
	fst_chunk = max_chunk / 2;
	sec_chunk = max_chunk / 2 + 1;
	while (*a_list)
	{
		if ((*a_list)->chunk_level == (fst_chunk - index)
			|| (*a_list)->chunk_level == (sec_chunk + index))
		{
			pa_pb(a_list, b_list, 'b');
			if ((*b_list)->chunk_level == (fst_chunk - index)
				&& (*b_list)->next
				&& (*b_list)->next->chunk_level == (sec_chunk + index))
				ra_rb(b_list, 'b');
		}
		if (!chunk_check(*a_list, fst_chunk - index, sec_chunk + index))
			index++;
		else
			ra_rb(a_list, 'a');
	}
	
}

void	chunk_list(double min, double max, t_list **a_list, double ratio)
{
	int		chunk_level;
	double	limit_chunk;
	t_list *tmp;

	limit_chunk = min + ratio;
	chunk_level = 1;
	tmp = *a_list;
	while (!(limit_chunk > max))
	{
		while (tmp)
		{
			if (tmp->chunk_level == 0 
				&& ((tmp->data == max && limit_chunk + ratio > max)
					|| (tmp->data >= min && tmp->data < limit_chunk)))
				tmp->chunk_level = chunk_level;
			tmp = tmp->next;
		}
		chunk_level++;
		tmp = *a_list;
		min = limit_chunk;
		limit_chunk = min + ratio;
	}
}

t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list)
{
	int max;
	int min;
	int divizor;

	if (len_a_list == 1)
		return (a_list);
	max = find_max(&a_list);
	min = find_min(&a_list);
	if (len_a_list < 6)
		divizor = 2;
	else
		divizor = 6;
	chunk_list(min, max, &a_list, (double)(max - min) / divizor);
	sort_by_chunk(&a_list, &b_list, divizor);
	print_chunk(a_list, 'a');
	print_chunk(b_list, 'b');
	sorted_a_list(&a_list, &b_list, divizor);
	print_list(a_list, "liste a : ");
	print_list(b_list, "liste b : ");
	return (a_list);
}
