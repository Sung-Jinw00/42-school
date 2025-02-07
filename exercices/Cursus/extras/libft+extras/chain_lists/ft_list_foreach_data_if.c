/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_data copy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 19:41:44 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* apply a function on each data of a list that match with data_ref */

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
