/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:34:26 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 17:59:29 by locagnio         ###   ########.fr       */
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

void	place_b_values(t_list **a_list, t_list *b_list)
{
	int		smaller_nb;
	int		bigger_nb;

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
	int cost;
	int pos_in_b;

	cost = 0;
	pos_in_b = find_lwr_val(b_list, find_min(&b_list), data);//je cherche la valeur inferieure dans b
	if (pos_data > len_list(a_list) / 2)
		pos_data = len_list(a_list) - pos_data;
	cost = pos_data + 1;//j'ajoute les mouvements pour passer la data dans b
	if (pos_in_b > len_list(b_list) / 2)
		cost += len_list(b_list) - pos_in_b;
	else//j'ajoute les mouvements pour recevoir la data de a et conserver le tri
		cost += pos_in_b;
	free_list(a_list);
	free_list(b_list);
	return (cost);
}

void	put_data_in_b(t_list **a_list, int pos_in_a, t_list **b_list, int pos_in_b)
{
	//r_or_rr(b_list, len_list(*b_list), pos_in_b);
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
		while (pos_in_b-- > 0)
			rra_rrb(b_list, 'b');
	}
	else if (pos_in_b <= len_list(*b_list) / 2)
		while (pos_in_b-- > 0)
			ra_rb(b_list, 'b');
	pa_pb(a_list, b_list, 'b');
}

void	cheapest_move_to_b(t_list **a_lst, t_list **b_lst)
{
	t_list	*tmp;
	int		cost;
	int		pos;
	int		pos_saved;

	while (*a_lst && len_list(*a_lst) != 3)//tant que j'ai plus de 3 nombres
	{
		tmp = *a_lst;
		pos = 0;//sa position
		pos_saved = pos;//je sauvegarde la position la plus avantageuse
		cost = cal_cost(lstdup(*a_lst), lstdup(*b_lst), pos, tmp->data);//je calcule le cout des mouvements
		while (tmp->next)
		{
			tmp = tmp->next;
			pos++;
			if (cost > cal_cost(lstdup(*a_lst), lstdup(*b_lst), pos, tmp->data))//si j'ai mieux
			{
				cost = cal_cost(lstdup(*a_lst), lstdup(*b_lst), pos, tmp->data);
				pos_saved = pos;//je sauvegarde la position la plus avantageuse
			}
		}//je met la data dans b a la bonne place
		pos = find_lwr_val(*b_lst, find_min(b_lst), get_at(*a_lst, pos_saved));
		put_data_in_b(a_lst, pos_saved, b_lst, pos);
	}
}

t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list)
{
	if (len_a_list == 1)
		return (a_list);
	if (len_a_list > 3 && !sorted_list_grow(a_list))
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
