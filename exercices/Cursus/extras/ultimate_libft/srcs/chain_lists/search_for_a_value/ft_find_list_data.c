/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_list_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Searches for a data in a chain list.
 * 
 * @returns
 * - 1 if the data was found in begin_list.*/
/**
 * - 0 if begin_list is NULL of if the data wasn't found.
*/
int	ft_list_find_data(t_list *begin_list, void *data_ref)
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (tmp->data == data_ref)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
