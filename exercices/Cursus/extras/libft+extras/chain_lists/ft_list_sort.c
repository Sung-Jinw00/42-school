/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:05:10 by marvin            #+#    #+#             */
/*   Updated: 2025/02/17 20:27:23 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* sort a list */

static int	ft_sorted_list(t_list *list)
{
	t_list	*tmp;
	int i;

	i = 0;
	tmp = list;
	while (tmp && tmp->next)
	{
		while (*(char *)(tmp->data + i) && *(char *)(tmp->next->data + i))
		{
			if (*(char *)(tmp->data + i) > *(char *)(tmp->next->data + i))
				return (0);
			else if (*(char *)(tmp->data + i) < *(char *)(tmp->next->data + i))
				break ;
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_list_sort2(t_list **prev, t_list **cur, t_list **after)
{
	while (*after)
	{
		if (ft_strcmp((*cur)->data, (*after)->data) > 0)
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

void	ft_list_sort(t_list **begin_list)
{
	t_list *prev;
	t_list *cur;
	t_list *after;

	while (!ft_sorted_list(*begin_list))
	{
		prev = *begin_list;
		cur = prev->next;
		after = cur->next;
		if (ft_strcmp(prev->data, cur->data) > 0)
		{
			prev->next = cur->next;
			cur->next = prev;
			*begin_list = cur;
			continue ;
		}
		ft_list_sort2(&prev, &cur, &after);
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