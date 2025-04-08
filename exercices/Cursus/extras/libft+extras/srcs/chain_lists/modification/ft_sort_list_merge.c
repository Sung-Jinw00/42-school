/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 16:43:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Merge 2 sorted lists together in begin_list1.
 * 
 * @note
 * If begin_list1 or begin_list2 isn't sorted, the function doesn't do anything.
 * 
 * @return
 * The new sorted list.
*/
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;
	t_list	*tmp;
	int		i;

	if (!ft_is_sorted_list(*begin_list1) || !ft_is_sorted_list(begin_list2))
		return ;
	i = 0;
	cur = NULL;
	tmp = *begin_list1;
	while (tmp || begin_list2)
	{
		if (tmp && (!begin_list2 || tmp->data <= begin_list2->data))
		{
			cur = add_at(cur, tmp->data, i++);
			tmp = tmp->next;
		}
		else if (begin_list2 && (!tmp || tmp->data > begin_list2->data))
		{
			cur = add_at(cur, begin_list2->data, i++);
			begin_list2 = begin_list2->next;
		}
	}
	free(*begin_list1);
	*begin_list1 = cur;
}
