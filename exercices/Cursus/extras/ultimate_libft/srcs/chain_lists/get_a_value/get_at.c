/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_at.c                                           :+:      :+:    :+:   */
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
 * Get a value in a chain list at the wished position.
 * 
 * @return
 * - If pos is out of the len of L, or if L is empty, it returns NULL.*/
/**
 * -Else, it returns the data.
*/
void	*get_at(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (!L)
		return (ft_write(2, "Get_at : Empty list\n"), NULL);
	else if (pos > len_list(L) || pos < 0)
		return (ft_write(2, "Get_at : Pos is out of the len of L\n"), NULL);
	while (i++ < pos)
		L = L->next;
	return (L->data);
}
