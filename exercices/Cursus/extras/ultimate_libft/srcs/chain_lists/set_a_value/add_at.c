/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Add a new cell that contains data in a chain list at the position wished.
 * 
 * @returns
 * - The chain list modified.
*/
t_list	*add_at(t_list *L, void *data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_cell	*cell;

	if (pos > len_list(L) || pos < 0)
		return (ft_write(2, "Add_at : Pos is out of the len of L\n"), NULL);
	cur = L;
	cell = create_cell(data);
	if (!cell)
		return (NULL);
	if (!L)
		return (cell);
	else if (pos == 0)
		return (cell->next = L, cell);
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
