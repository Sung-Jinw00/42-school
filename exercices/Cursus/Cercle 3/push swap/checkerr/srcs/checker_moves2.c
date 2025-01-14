/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:53:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 19:25:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_rr(t_list **a_list, t_list **b_list)
{
	c_ra_rb(a_list);
	c_ra_rb(b_list);
}

void	c_rra_rrb(t_list **list)
{
	t_list	*last;
	t_list	*before_last;

	if (!*list)
		return ;
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
}

void	c_rrr(t_list **a_list, t_list **b_list)
{
	c_rra_rrb(a_list);
	c_rra_rrb(b_list);
}
