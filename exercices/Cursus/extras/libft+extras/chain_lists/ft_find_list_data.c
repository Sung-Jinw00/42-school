/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_list_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/12 16:42:06 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* tell if a data in the list */

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
