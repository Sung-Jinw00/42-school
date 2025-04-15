/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:30:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Reverse a chain list.
*/
void	ft_list_reverse(t_list **begin_list)
{
	t_list	*copy;
	t_list	*cur;
	int		len;

	len = len_list(*begin_list) - 1;
	copy = ft_listdup(*begin_list);
	*begin_list = create_cell(get_at(copy, len));
	cur = *begin_list;
	while (len-- > 0)
	{
		cur->next = create_cell(get_at(copy, len));
		cur = cur->next;
	}
	cur->next = NULL;
	free(copy);
}
