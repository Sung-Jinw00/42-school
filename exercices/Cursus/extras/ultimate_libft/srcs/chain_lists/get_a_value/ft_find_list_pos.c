/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_list_pos.c                                 :+:      :+:    :+:   */
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
 * Searches for a data in a chain list and returns the position of this data.
 * 
 * @returns
 * - pos if the data was found in begin_list.*/
/**
 * - 0 if begin_list is NULL of if the data wasn't found.
*/
int	ft_list_find_pos(t_list *begin_list, void *data_ref)
{
	t_list	*tmp;
	int		pos;

	tmp = begin_list;
	pos = 0;
	while (tmp)
	{
		if (tmp->data == data_ref)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}
