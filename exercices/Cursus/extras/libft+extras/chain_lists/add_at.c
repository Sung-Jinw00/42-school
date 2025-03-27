/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/27 20:31:36 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* add a cew cell to the chain list with the data and position in the list
	specified
*/
t_list	*add_at(t_list *L, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_cell	*cell;

	cur = L;
	cell = create_cell(data);
	if (!cell)
		return (NULL);
	if (!L)
		return (cell);
	else if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	i = 0;
	while (i++ < pos)
	{
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (L);
}
