/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 20:32:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* remove a cell that contains data_ref */

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
