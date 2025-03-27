/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_list_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/27 20:30:19 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* find the position of the data in the list
*/
t_list	*ft_list_find_pos(t_list *begin_list, void *data_ref)
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
