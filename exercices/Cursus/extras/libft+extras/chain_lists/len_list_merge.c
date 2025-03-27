/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_list_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/27 20:28:17 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* merge 2 lists together
*/
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	cur = *begin_list1;
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
}
