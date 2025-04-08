/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Set a value in a chain list at the wished position.
 * 
 * @note
 * The value replaced by the function isn't free, it's the responsibility of
 * the user to free the memory of the data if needed.
*/
void	set_at(t_list *L, void *data, int pos)
{
	int	i;

	i = 0;
	if (!L)
		return ((void)ft_write(2, "Set_at : Empty list\n"));
	else if (pos > len_list(L) || pos < 0)
		return ((void)ft_write(2, "Set_at : Pos is out of the len of L\n"));
	while (i++ < pos)
		L = L->next;
	L->data = data;
}
