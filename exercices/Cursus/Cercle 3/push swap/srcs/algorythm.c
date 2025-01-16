/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:26 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:43:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_b_values(t_list **a_list, t_list *b_list)
{
	int	smaller_nb;
	int	bigger_nb;

	while (b_list)
	{
		smaller_nb = find_min(a_list);
		bigger_nb = find_max(a_list);
		if (b_list->data < smaller_nb)
			if_is_min(a_list, smaller_nb);
		else if (b_list->data > bigger_nb)
			if_is_max(a_list, bigger_nb);
		else if (smaller_nb < b_list->data && b_list->data < bigger_nb)
			*a_list = pos_of_value_for_b2(a_list, b_list, bigger_nb);
		pa_pb(a_list, &b_list, 'a');
	}
}

int	cal_cost(t_list *a_list, t_list *b_list, int pos_data, int data)
{
	int	cost;
	int	pos_in_b;

	cost = 0;
	pos_in_b = find_lwr_val(b_list, find_min(&b_list), data);
	if (pos_data > len_list(a_list) / 2)
		pos_data = len_list(a_list) - pos_data;
	cost = pos_data + 1;
	if (pos_in_b > len_list(b_list) / 2)
		cost += len_list(b_list) - pos_in_b;
	else
		cost += pos_in_b;
	return (cost);
}

void	put_data_in_b(t_list **a_list, int pos_a, t_list **b_list, int pos_b)
{
	if (pos_a <= len_list(*a_list) / 2 && pos_b <= len_list(*b_list) / 2)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a_list, b_list);
			pos_a--;
			pos_b--;
		}
	}
	else if (pos_a > len_list(*a_list) / 2 && pos_b > len_list(*b_list) / 2)
	{
		pos_a = len_list(*a_list) - pos_a;
		pos_b = len_list(*b_list) - pos_b;
		while (pos_a > 0 && pos_b > 0)
		{
			rrr(a_list, b_list);
			pos_a--;
			pos_b--;
		}
		pos_a = len_list(*a_list) - pos_a;
		pos_b = len_list(*b_list) - pos_b;
	}
	r_or_rr(a_list, len_list(*a_list), pos_a, 'a');
	r_or_rr(b_list, len_list(*b_list), pos_b, 'b');
	pa_pb(a_list, b_list, 'b');
}

void	cheapest_move_to_b(t_list **a_lst, t_list **b_lst)
{
	t_list	*tmp;
	int		cost;
	int		pos;
	int		pos_saved;

	while (*a_lst && len_list(*a_lst) != 3)
	{
		tmp = *a_lst;
		pos = 0;
		pos_saved = pos;
		cost = cal_cost(*a_lst, *b_lst, pos, tmp->data);
		while (tmp->next)
		{
			tmp = tmp->next;
			pos++;
			if (cost > cal_cost(*a_lst, *b_lst, pos, tmp->data))
			{
				cost = cal_cost(*a_lst, *b_lst, pos, tmp->data);
				pos_saved = pos;
			}
		}
		pos = find_lwr_val(*b_lst, find_min(b_lst), get_at(*a_lst, pos_saved));
		put_data_in_b(a_lst, pos_saved, b_lst, pos);
	}
}

t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list)
{
	if (len_a_list == 1)
		return (a_list);
	if (len_a_list > 3)
	{
		pa_pb(&a_list, &b_list, 'b');
		pa_pb(&a_list, &b_list, 'b');
		cheapest_move_to_b(&a_list, &b_list);
	}
	if (len_list(a_list) == 3)
		sort_a(&a_list);
	place_b_values(&a_list, b_list);
	final_moves(&a_list, find_min(&a_list));
	return (a_list);
}

// print_vals(a_list, b_list);