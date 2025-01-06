/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:53:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 21:44:27 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* decale toutes les valeurs d'une position vers le haut pour les deux listes */
void	rr(t_list **list_a, t_list **list_b)
{
	t_list *last_a;
	t_list *first_a;
	t_list *last_b;
	t_list *first_b;

	last_a = *list_a;
	first_a = *list_a;
	while (last_a->next)
		last_a = last_a->next;//je vais a la fin de la liste
	last_a->next = first_a;//je pointe vers le premier, il deviendra donc le nouveau dernier
	*list_a = (*list_a)->next;//le debut de la liste devient la 2eme valeur
	first_a->next = NULL;//la premiere valeur pointe vers null
	last_b = *list_b;
	first_b = *list_b;
	while (last_b->next)
		last_b = last_b->next;
	last_b->next = first_b;
	*list_b = (*list_b)->next;
	first_b->next = NULL;
	ft_printf("rr\n");
}

/* decale toutes les valeurs d'une position vers le bas, le dernier deviens le premier */
void	rra_rrb(t_list **list, char chosen_list)
{
	t_list *last;
	t_list *before_last;

	before_last = *list;
	while (before_last->next->next)
		before_last = before_last->next;//je vais a l'avant-dernier
	last = before_last->next;//je pointe la fin
	before_last->next = NULL;//l'avant-dernier pointe vers null
	last->next = *list;//le dernier pointe sur le premier
	*list = last;//le dernier devient le debut de la liste
	print_action("rr", chosen_list);
}

/* decale toutes les valeurs d'une position vers le bas pour les deux listes */
void	rrr(t_list **list_a, t_list **list_b)
{
	t_list *last_a;
	t_list *before_last_a;
	t_list *last_b;
	t_list *before_last_b;

	before_last_a = *list_a;
	while (before_last_a->next->next)
		before_last_a = before_last_a->next;//je vais a l'avant-dernier
	last_a = before_last_a->next;//je pointe la fin
	before_last_a->next = NULL;//l'avant-dernier pointe vers null
	last_a->next = *list_a;//le dernier pointe sur le premier
	*list_a = last_a;//le dernier devient le debut de la liste
	before_last_b = *list_b;
	while (before_last_b->next->next)
		before_last_b = before_last_b->next;//je vais a l'avant-dernier
	last_b = before_last_b->next;//je pointe la fin
	before_last_b->next = NULL;//l'avant-dernier pointe vers null
	last_b->next = *list_b;//le dernier pointe sur le premier
	*list_b = last_b;//le dernier devient le debut de la liste
	ft_printf("rr\n");
}
