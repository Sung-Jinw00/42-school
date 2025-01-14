/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:53:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:40:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a_list, t_list **b_list)
{
	ra_rb(a_list, 0);
	ra_rb(b_list, 0);
	ft_printf("rr\n");
}

void	rra_rrb(t_list **list, char chosen_list)
{
	t_list	*last;
	t_list	*before_last;

	before_last = *list;
	if (before_last->next && before_last->next->next)
	{
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *list;
		*list = last;
	}
	print_action("rr", chosen_list);
}

void	rrr(t_list **a_list, t_list **b_list)
{
	rra_rrb(a_list, 0);
	rra_rrb(b_list, 0);
	ft_printf("rrr\n");
}
