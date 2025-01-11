/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:53:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/11 15:22:32 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* decale toutes les valeurs d'une position vers le haut pour les deux listes */
void	rr(t_list **a_list, t_list **b_list)
{
	ra_rb(a_list, 0);
	ra_rb(b_list, 0);
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
	rra_rrb(a_list, 0);
	rra_rrb(b_list, 0);
	ft_printf("rrr\n");
}
