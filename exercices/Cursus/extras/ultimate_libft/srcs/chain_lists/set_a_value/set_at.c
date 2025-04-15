/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_at.c                                           :+:      :+:    :+:   */
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
 * Set a value in a chain list at the wished position.
 * 
 * @note
 * The value replaced by the function isn't free, it's the responsibility of
 * the user to free the memory of the data if needed.
*/
void	set_at(t_list *L, void *data, int pos)
{
	int	i;

	if (!L)
		return ((void)ft_write(2, "Set_at : Empty list\n"));
	else if (pos > len_list(L) || pos < 0)
		return ((void)ft_write(2, "Set_at : Pos is out of the len of L\n"));
	i = 0;
	while (i++ < pos)
		L = L->next;
	L->data = data;
}
