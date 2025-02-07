/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 21:49:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* merge 2 sorted lists together */

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;
	t_list	*tmp;
	int		i;

	i = 0;
	cur = NULL;
	tmp = *begin_list1;
	while (tmp || begin_list2)
	{
		if (tmp->data <= begin_list2->data)
		{
			cur = add_at(cur, tmp->data, i++);
			*begin_list1 = tmp;
			tmp = tmp->next;
			free(*begin_list1);
		}
		else if (tmp->data > begin_list2->data)
		{
			cur = add_at(cur, begin_list2->data, i++);
			begin_list2 = begin_list2->next;
		}
	}
	*begin_list1 = cur;
}
