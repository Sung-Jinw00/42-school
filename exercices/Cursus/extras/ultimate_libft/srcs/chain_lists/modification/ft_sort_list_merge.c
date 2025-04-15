/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_merge.c                               :+:      :+:    :+:   */
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
 * Merge 2 lists together in begin_list1 and sort it.
 * 
 * @note
 * The memory allocation is shared between begin_list2 and the merged part of
 * begin_list2 in begin_list1. The user should be careful if begin_list2 is
 * freed (if a duplicate wasn't given to the function).
 * 
 * @return
 * The new sorted list.
*/
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1);
}
