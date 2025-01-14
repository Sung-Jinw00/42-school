/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:47:15 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:49:41 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_sa_sb(t_list **list)
{
	t_list	*prev;
	t_list	*cur;

	if (!(*list)->next)
		return ;
	if ((*list)->data && (*list)->next->data)
	{
		prev = *list;
		cur = prev->next;
		prev->next = cur->next;
		cur->next = prev;
		*list = cur;
	}
}

void	c_ss(t_list **a_list, t_list **b_list)
{
	c_sa_sb(a_list);
	c_sa_sb(b_list);
}

void	c_pa_pb(t_list **a_list, t_list **b_list, char destination)
{
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;
	t_list	*second_b;

	if (destination == 'a')
	{
		first_b = *b_list;
		second_b = first_b->next;
		first_a = *a_list;
		first_b->next = first_a;
		*a_list = first_b;
		*b_list = second_b;
	}
	else
	{
		first_a = *a_list;
		second_a = first_a->next;
		first_b = *b_list;
		first_a->next = first_b;
		*b_list = first_a;
		*a_list = second_a;
	}
}

void	c_ra_rb(t_list **list)
{
	t_list	*last;
	t_list	*first;

	if (!(*list)->next)
		return ;
	last = *list;
	first = *list;
	while (last->next)
		last = last->next;
	last->next = first;
	*list = (*list)->next;
	first->next = NULL;
}
