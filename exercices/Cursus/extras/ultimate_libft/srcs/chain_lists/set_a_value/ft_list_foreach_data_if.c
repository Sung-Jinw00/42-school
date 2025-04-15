/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_data_if.c                          :+:      :+:    :+:   */
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
 * Apply a function on each data of a list that match with data_ref.
 * 
 * @param f The function that will be applied for each data that matches with
 * data_ref.
 * @param data_ref The data to find in the chain list that will received the
 * modification of f.
*/
void	ft_list_foreach_data_if(t_list *begin_list, void (*f)(void *),
		void *data_ref)
{
	t_list	*cur;

	cur = begin_list;
	while (cur)
	{
		if (cur->data == data_ref)
			(*f)(cur->data);
		cur = cur->next;
	}
}
