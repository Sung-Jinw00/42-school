/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:47:15 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 21:41:18 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* intervertit les 2 premiers elements du sommet de la liste */
void	sa_sb(t_list **list, char chosen_list)
{
	t_list *prev;
	t_list *cur;

	if ((*list)->data && (*list)->next->data)
	{
		prev = *list;
		cur = prev->next;
		prev->next = cur->next;
		cur->next = prev;
		*list = cur;
	}
	print_action("s", chosen_list);
}

/* intervertit les 2 premiers elements du sommet des deux listes */
void	ss(t_list **list_a, t_list **list_b)
{
	t_list *prev_a;
	t_list *cur_a;
	t_list *prev_b;
	t_list *cur_b;

	if ((*list_a)->data && (*list_a)->next->data
		&& (*list_b)->data && (*list_b)->next->data)
	{
		prev_a = *list_a;
		cur_a = prev_a->next;
		prev_a->next = cur_a->next;
		cur_a->next = prev_a;
		*list_a = cur_a;
		prev_b = *list_a;
		cur_b = prev_b->next;
		prev_b->next = cur_b->next;
		cur_b->next = prev_b;
		*list_a = cur_b;
	}
	ft_printf("ss\n");
}

/* prend le premier element d'une liste et l'integre a l'autre liste comme premier element */
void	pa_pb(t_list **list_a, t_list **list_b, char destination)
{
	t_list *first_a;
	t_list *second_a;
	t_list *first_b;
	t_list *second_b;

	if (destination == 'a')
	{
		first_b = *list_b;
		second_b = first_b->next;
		first_a = *list_a;
		first_b->next = first_a;
		*list_a = first_b;
		*list_b = second_b;
	}
	else
	{
		first_a = *list_a;
		second_a = first_a->next;
		first_b = *list_b;
		first_a->next = first_b;
		*list_b = first_a;
		*list_a = second_a;
	}
	print_action("p", destination);
}

/* decale toutes les valeurs d'une position vers le haut, le premier deviens le dernier */
void	ra_rb(t_list **list, char chosen_list)
{
	t_list *last;
	t_list *first;

	last = *list;
	first = *list;
	while (last->next)
		last = last->next;
	last->next = first;
	*list = (*list)->next;
	first->next = NULL;
	print_action("r", chosen_list);
}
