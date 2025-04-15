/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
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
 * Remove each data of a list that match with data_ref.
*/
void	ft_list_remove_if(t_list **begin_list, void *data_ref)
{
	t_list	*tmp;
	int		pos;

	tmp = *begin_list;
	pos = 0;
	while (tmp)
	{
		if (tmp->data == data_ref)
			free_at(tmp, pos);
		tmp = tmp->next;
		pos++;
	}
}
