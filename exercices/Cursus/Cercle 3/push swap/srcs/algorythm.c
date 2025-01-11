/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:26 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/12 00:50:46 by marvin           ###   ########.fr       */
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

int	calculate_cost(t_list *a_list, t_list *b_list, int pos_data, int data)
{
	int cost;
	int pos_in_b;

	cost = 0;
	pos_in_b = find_a_value(b_list, find_min(&b_list), data, "smaller");
	while(!sorted_list_degrow(b_list))
	{
		if (pos_data > len_list(a_list) / 2)
			pos_data = len_list(a_list) - pos_data;
		cost = pos_data + 1;//on compte le nombre de coups qu'il faudrait pour pouvoir faire passer la data dans b
		if (pos_in_b > len_list(b_list) / 2)
			cost += len_list(b_list) - pos_in_b;
		else
			cost += pos_in_b;
	}
	free_list(a_list);
	free_list(b_list);
	return (cost);
}

void	put_data_in_b(t_list **a_list, int pos_in_a, t_list **b_list, int pos_in_b)
{
	if (pos_in_a > len_list(*a_list) / 2)
	{
		pos_in_a = len_list(*a_list) - pos_in_a;
		while (pos_in_a > 0)
			rra_rrb(a_list, 'a');
	}
	else if (pos_in_a <= len_list(*a_list) / 2)
		while (pos_in_a > 0)
			ra_rb(a_list, 'a');
	if (pos_in_b > len_list(*b_list) / 2)
	{
		pos_in_b = len_list(*b_list) - pos_in_b;
		while (pos_in_b > 0)
			rra_rrb(b_list, 'b');
	}
	else if (pos_in_b <= len_list(*b_list) / 2)
		while (pos_in_b > 0)
			ra_rb(b_list, 'b');
	pa_pb(a_list, b_list, 'b');
}

void	cheapest_move_to_b(t_list **a_list, t_list **b_list)
{
	t_list	*tmp;
	int		data;
	int		cost;
	int		pos;
	int		pos_saved;

	while (*a_list && len_list(*a_list) != 3)
	{
		tmp = *a_list;
		data = tmp->data;
		pos = 0;
		pos_saved = pos;
		cost = calculate_cost(ft_listdup(*a_list), ft_listdup(*b_list), pos, data);
		while (tmp->next)
		{
			tmp = tmp->next;
			pos++;
			if (cost > calculate_cost(ft_listdup(*a_list), ft_listdup(*b_list), pos, data))
			{
				cost = calculate_cost(ft_listdup(*a_list), ft_listdup(*b_list), pos, data);
				pos_saved = pos;
			}
		}
		put_data_in_b(a_list, pos_saved, b_list, find_a_value(*b_list, find_min(b_list), data, "smaller"));
	}
}

t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list)
{
	if (len_a_list == 1)
		return (a_list);
	pa_pb(&a_list, &b_list, 'b');
	pa_pb(&a_list, &b_list, 'b');
	cheapest_move_to_b(&a_list, &b_list);
	//print_vals_and_chunks(a_list, b_list);
	sort_a(&a_list);
	pos_of_value_for_b(&a_list, b_list);
	//ft_printf("\n");
	//print_vals_and_chunks(a_list, b_list);
	//ft_printf("\n");
	return (a_list);
}
