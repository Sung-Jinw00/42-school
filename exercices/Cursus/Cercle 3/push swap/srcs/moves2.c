/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:53:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/08 20:53:38 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* decale toutes les valeurs d'une position vers le haut pour les deux listes */
void	rr(t_list **a_list, t_list **b_list)
{
	t_list *last_a;
	t_list *first_a;
	t_list *last_b;
	t_list *first_b;

	last_a = *a_list;
	first_a = *a_list;
	if (last_a->next)
	{
		while (last_a->next)
			last_a = last_a->next;//je vais a la fin de la liste
		last_a->next = first_a;//je pointe vers le premier, il deviendra donc le nouveau dernier
		*a_list = (*a_list)->next;//le debut de la liste devient la 2eme valeur
		first_a->next = NULL;//la premiere valeur pointe vers null
	}
	last_b = *b_list;
	first_b = *b_list;
	if (last_a->next)
	{
		while (last_b->next)
			last_b = last_b->next;
		last_b->next = first_b;
		*b_list = (*b_list)->next;
		first_b->next = NULL;
	}
	ft_printf("rr\n");
}

/* decale toutes les valeurs d'une position vers le bas, le dernier deviens le premier */
void	rra_rrb(t_list **list, char chosen_list)
{
	t_list *last;
	t_list *before_last;

	before_last = *list;
	if (before_last->next && before_last->next->next)
	{
		while (before_last->next->next)
			before_last = before_last->next;//je vais a l'avant-dernier
		last = before_last->next;//je pointe la fin
		before_last->next = NULL;//l'avant-dernier pointe vers null
		last->next = *list;//le dernier pointe sur le premier
		*list = last;//le dernier devient le debut de la liste
	}
	print_action("rr", chosen_list);
}

/* decale toutes les valeurs d'une position vers le bas pour les deux listes */
void	rrr(t_list **a_list, t_list **b_list)
{
	t_list *last_a;
	t_list *before_last_a;
	t_list *last_b;
	t_list *before_last_b;

	before_last_a = *a_list;
	if (before_last_a->next && before_last_a->next->next)
	{
		while (before_last_a->next->next)
			before_last_a = before_last_a->next;//je vais a l'avant-dernier
		last_a = before_last_a->next;//je pointe la fin
		before_last_a->next = NULL;//l'avant-dernier pointe vers null
		last_a->next = *a_list;//le dernier pointe sur le premier
		*a_list = last_a;//le dernier devient le debut de la liste
	}
	before_last_b = *b_list;
	if (before_last_b->next && before_last_b->next->next)
	{
		while (before_last_b->next->next)
			before_last_b = before_last_b->next;//je vais a l'avant-dernier
		last_b = before_last_b->next;//je pointe la fin
		before_last_b->next = NULL;//l'avant-dernier pointe vers null
		last_b->next = *b_list;//le dernier pointe sur le premier
		*b_list = last_b;//le dernier devient le debut de la liste
	}
	ft_printf("rrr\n");
}
