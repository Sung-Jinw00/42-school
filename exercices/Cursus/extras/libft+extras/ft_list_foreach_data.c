/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 19:39:33 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* apply a function on each data of a list */

void	ft_list_foreach_data(t_list *begin_list, void (*f)(void *))
{
	t_list	*cur;

	cur = begin_list;
	while (cur)
	{
		(*f)(cur->data);
		cur = cur->next;
	}
}
