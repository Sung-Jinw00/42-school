/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:47:15 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/11 16:08:43 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* intervertit les 2 premiers elements du sommet de la liste */
void	sa_sb(t_list **list, char chosen_list)
{
	t_list *prev;
	t_list *cur;

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
	print_action("s", chosen_list);
}

/* intervertit les 2 premiers elements du sommet des deux listes */
void	ss(t_list **a_list, t_list **b_list)
{
	sa_sb(a_list, 0);
	sa_sb(b_list, 0);
	ft_printf("ss\n");
}

/* prend le premier element d'une liste et l'integre a l'autre liste comme premier element */
void	pa_pb(t_list **a_list, t_list **b_list, char destination)
{
	t_list *first_a;
	t_list *second_a;
	t_list *first_b;
	t_list *second_b;

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
	print_action("p", destination);
}

/* decale toutes les valeurs d'une position vers le haut, le premier deviens le dernier */
void	ra_rb(t_list **list, char chosen_list)
{
	t_list *last;
	t_list *first;

	if (!(*list)->next)
		return ;
	last = *list;
	first = *list;
	while (last->next)
		last = last->next;
	last->next = first;
	*list = (*list)->next;
	first->next = NULL;
	print_action("r", chosen_list);
}
