/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
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
 * Concatenates two chain lists together in begin_list1.
 * 
 * @note
 * The memory allocation is shared between begin_list2 and the merged part
 * of begin_list1 that correspond to begin_list2. The user should be careful
 * if begin_list2 is freed (if a duplicate wasn't given to the function).
*/
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	if (!begin_list2)
		return ;
	if (!*begin_list1)
		*begin_list1 = begin_list2;
	cur = *begin_list1;
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
}
