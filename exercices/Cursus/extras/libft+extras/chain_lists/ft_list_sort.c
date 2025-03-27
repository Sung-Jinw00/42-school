/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:05:10 by marvin            #+#    #+#             */
/*   Updated: 2025/03/27 20:29:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

static int	ft_sorted_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sort_one_go2(t_list **prev, t_list **cur, t_list **after,
		t_list **tmp)
{
	while (*after)
	{
		if ((*cur)->data > (*after)->data)
		{
			*tmp = *after;
			*after = *cur;
			*cur = *tmp;
			(*after)->next = (*cur)->next;
			(*prev)->next = *cur;
			(*cur)->next = *after;
		}
		(*prev) = (*cur);
		(*cur) = (*after);
		(*after) = (*after)->next;
	}
}

static void	sort_one_go(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*after;
	t_list	*tmp;

	prev = *begin_list;
	cur = prev->next;
	after = cur->next;
	if (prev->data > cur->data && after)
	{
		prev->next = after;
		cur->next = prev;
		*begin_list = cur;
	}
	sort_one_go2(&prev, &cur, &after, &tmp);
}

/* sort a list that contain strings as arguments
*/
void	ft_list_sort(t_list **begin_list)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*after;
	t_list	*tmp;

	if (!*begin_list)
		return ;
	tmp = NULL;
	prev = *begin_list;
	cur = prev->next;
	if (!cur)
		return ;
	after = cur->next;
	if (prev->data > cur->data && !after)
	{
		prev->next = NULL;
		cur->next = prev;
		*begin_list = cur;
		return ;
	}
	else
		while (!ft_sorted_list(*begin_list))
			sort_one_go(begin_list);
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