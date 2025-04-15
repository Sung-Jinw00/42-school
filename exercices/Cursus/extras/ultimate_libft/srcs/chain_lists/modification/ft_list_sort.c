/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:05:10 by marvin            #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static void	ft_env_sort2(t_list **prev, t_list **cur, t_list **after)
{
	while (*after)
	{
		if (ft_strcmp((char *)(*cur)->data, (char *)(*after)->data) > 0)
		{
			(*cur)->next = (*after)->next;
			(*after)->next = *cur;
			(*prev)->next = *after;
			break ;
		}
		*prev = (*prev)->next;
		*cur = (*prev)->next;
		*after = (*cur)->next;
	}
}

/**
 * @brief
 * Sort a chain list.
*/
void	ft_list_sort(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*after;

	while (!ft_is_sorted_list(*begin_list))
	{
		prev = *begin_list;
		cur = prev->next;
		after = cur->next;
		if (ft_strcmp((char *)prev->data, (char *)cur->data) > 0)
		{
			prev->next = cur->next;
			cur->next = prev;
			*begin_list = cur;
			continue ;
		}
		ft_env_sort2(&prev, &cur, &after);
	}
}

/* int main(void)
{
	t_list *newlist;

	newlist = NULL;
	newlist = add_at(newlist, 1, 0);
	newlist = add_at(newlist, 3, 1);
	newlist = add_at(newlist, 2, 2);
	newlist = add_at(newlist, 4, 3);
	newlist = add_at(newlist, 8, 4);
	newlist = add_at(newlist, 7, 5);
	newlist = add_at(newlist, 5, 6);
	newlist = add_at(newlist, 6, 7);
	print_list(newlist);
	ft_list_sort(&newlist);
	print_list(newlist);
} */