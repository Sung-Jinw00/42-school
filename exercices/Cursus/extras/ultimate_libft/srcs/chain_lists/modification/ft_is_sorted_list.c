/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:05:10 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Check if a list is sorted.
 * 
 * @return
 * - 1 if the list is sorted.*/
/**
 * - 0 if the list isn't sorted or if list is NULL.
*/
int	ft_is_sorted_list(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return (0);
	tmp = list;
	while (tmp && tmp->next)
	{
		if (ft_strcmp((char *)tmp->data, (char *)tmp->next->data) > 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
