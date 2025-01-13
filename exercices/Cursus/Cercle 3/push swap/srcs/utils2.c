/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:38:13 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 18:13:35 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*free_list(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free (list);
		list = tmp;
	}
	return (list);
}

void	print_action(char *action, char chosen_list)
{
	if (chosen_list == 0)
		return ;
	ft_printf("%s%c\n", action, chosen_list);
}

int	sorted_list_grow(t_list *list)
{
	t_list *prev;
	t_list *cur;

	prev = list;
	cur = prev->next;
	while (prev && cur)
	{
		if (prev->data > cur->data
			&& !(prev->data == find_max(&list) && cur->data == find_min(&list)))
			return (0);
		prev = cur;
		cur = prev->next;
	}
	return (1);
}
int	sorted_a_list(t_list *a_list)
{
	t_list *prev;
	t_list *cur;

	prev = a_list;
	if (prev->data != find_min(&a_list))
		return (0);
	cur = prev->next;
	while (prev && cur)
	{
		if (prev->data > cur->data)
			return (0);
		prev = cur;
		cur = prev->next;
	}
	return (1);
}

int	find_lwr_val(t_list *list, int min, int data)
{
	t_list *tmp;
	int pos;
	int	value_to_find;

	tmp = list;
	value_to_find = min;
	while (tmp)
	{
		if (tmp->data > value_to_find && tmp->data < data)
			value_to_find = tmp->data;//je garde la valeur en dessous de ma valeur actuelle
		tmp = tmp->next;
	}
	tmp = list;
	pos = 0;
	while (tmp && tmp->data != value_to_find)
	{
		tmp = tmp->next;
		pos++;
	}
	if (min > data && pos < len_list(list))
		pos += 1;
	else if (min > data && pos == len_list(list))
		pos = 0;
	return (pos);//je recupere la position
}
