/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:26 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/11 22:15:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_moves(t_list **a_list, int smaller_nb)
{
	int pos;
	t_list *tmp;

	tmp = *a_list;
	pos = 0;
	while (tmp->data != smaller_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	r_or_rr(a_list, len_list(*a_list), pos);
}

void	pos_of_value_for_b(t_list **a_list, t_list *b_list)
{
	int		smaller_nb;
	int		bigger_nb;

	while (b_list)
	{
		smaller_nb = find_min(a_list);
		bigger_nb = find_max(a_list);
		//print_vals_and_chunks(*a_list, b_list);
		if (b_list->data < smaller_nb)
			if_is_min(a_list, smaller_nb);
		else if (b_list->data > bigger_nb)
			if_is_max(a_list, bigger_nb);
		else if (smaller_nb < b_list->data && b_list->data < bigger_nb)
			*a_list = pos_of_value_for_b2(a_list, b_list, bigger_nb);
		//print_vals_and_chunks(*a_list, b_list);
		pa_pb(a_list, &b_list, 'a');
	}
	final_moves(a_list, find_min(a_list));
	//print_vals_and_chunks(*a_list, b_list);
}

int	last_chunk2(t_list *tmp, int last_valid_value, int len_list_tmp)
{
	int i;

	i = 0;
	while (tmp && tmp->data != last_valid_value)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > len_list_tmp / 2)
		i = len_list_tmp - i;
	return (i);
}

int	last_chunk(t_list *a_list, int chunk1, int chunk2)
{
	t_list *tmp;
	int		last_valid_value;
	int trigger;

	trigger = 0;
	tmp = a_list;
	last_valid_value = 0;
	while (tmp)
	{
		if (tmp->chunk_level == chunk1 || tmp->chunk_level == chunk2)
		{
			last_valid_value = tmp->data;
			trigger = 1;
		}
		tmp = tmp->next;
	}
	if (trigger == 0)
		return (-1);
	tmp = a_list;
	return (last_chunk2(tmp, last_valid_value, len_list(tmp)));
}

int	first_chunk(t_list *a_list, int chunk1, int chunk2)
{
	t_list	*tmp;
	int		first_valid_value;
	int		i;

	tmp = a_list;
	first_valid_value = 0;
	while (tmp && !(tmp->chunk_level == chunk1 || tmp->chunk_level == chunk2))
		tmp = tmp->next;
	if (tmp && (tmp->chunk_level == chunk1 || tmp->chunk_level == chunk2))
		first_valid_value = tmp->data;
	else
		return (-1);
	tmp = a_list;
	i = 0;
	while (tmp->data != first_valid_value)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	opti_chunk_mv(t_list **a_list, int chunk1, int chunk2)
{
	t_list	*tmp;
	int		frst_chunk;
	int		lst_chunk;

	tmp = *a_list;
	tmp = tmp->next;
	if (!tmp)
		return ;
	frst_chunk = first_chunk(*a_list, chunk1, chunk2);
	lst_chunk = last_chunk(*a_list, chunk1, chunk2);
	if (frst_chunk != -1 && frst_chunk != 0 && frst_chunk <= lst_chunk
		&& frst_chunk <= len_list(*a_list) / 2)
	{
		while (frst_chunk-- > 0)
			ra_rb(a_list, 'a');
	}
	else if (frst_chunk != -1  && frst_chunk != 0 && frst_chunk > lst_chunk)
		while (lst_chunk-- > 0)
			rra_rrb(a_list, 'a');
}


void	sort_by_chunk2(t_list **a_list, t_list **b_list, int chunk1, int chunk2)
{
	int frst_chunk;
	int lst_chunk;
	frst_chunk = first_chunk(*a_list, chunk1, chunk2);
	lst_chunk = last_chunk(*a_list, chunk1, chunk2);
	//ft_printf("chunk1 : %d\nchunk2 : %d\nlen_list_a : %d\n", chunk1, chunk2, len_list(*a_list));
	if (frst_chunk != -1  && frst_chunk != 0 && frst_chunk <= lst_chunk
		&& frst_chunk <= len_list(*a_list) / 2)
		rr(a_list, b_list);
	else
		ra_rb(b_list, 'b');
}

void	sort_by_chunk(t_list **a_list, t_list **b_list, int max_chunk)
{
	int 	index;
	int		chunk1;
	int		chunk2;

	index = 0;
	chunk1 = max_chunk / 2;//je prends les 2 chunks medians
	chunk2 = max_chunk / 2 + 1;
	while (*a_list && len_list(*a_list) != 3)
	{
		if ((*a_list)->chunk_level == (chunk1 - index)
			|| (*a_list)->chunk_level == (chunk2 + index))//si j'ai un chunk qui correspond
		{
			pa_pb(a_list, b_list, 'b');
			if ((*b_list)->next
				&& (*b_list)->chunk_level < (*b_list)->next->chunk_level)
				sort_by_chunk2(a_list, b_list, chunk1 - index, chunk2 + index);
		}
		if (!chunk_check(*a_list, chunk1 - index, chunk2 + index))//si je trouve plus mes chunks dans a, je passe aux suivants
			index++;
		if (*a_list && !((*a_list)->chunk_level == chunk1 - index
			|| (*a_list)->chunk_level == chunk2 + index))//sinon je cherche le prochain
			opti_chunk_mv(a_list, chunk1 - index, chunk2 + index);
		//print_vals_and_chunks(*a_list, *b_list);
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
	while (!(limit_chunk > max + 0.1))
	{
		while (tmp)
		{
			if (tmp->chunk_level == 0 
				&& ((tmp->data == max && limit_chunk + ratio > max + 0.1)
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
	if (len_a_list < 100)
		divizor = 2;
	else if (len_a_list >= 100 && len_a_list < 500)
		divizor = 10;
	else
		divizor = 6;
	chunk_list(min, max, &a_list, (double)(max - min) / divizor);
	//print_vals_and_chunks(a_list, b_list);
	sort_by_chunk(&a_list, &b_list, divizor);
	//print_vals_and_chunks(a_list, b_list);
	sort_a(&a_list);
	pos_of_value_for_b(&a_list, b_list);
	//ft_printf("\n");
	//print_vals_and_chunks(a_list, b_list);
	//ft_printf("\n");
	return (a_list);
}
