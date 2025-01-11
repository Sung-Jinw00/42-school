/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:38:13 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/12 00:48:00 by marvin           ###   ########.fr       */
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

int	sorted_list_degrow(t_list *list)
{
	t_list *prev;
	t_list *cur;

	prev = list;
	cur = prev->next;
	while (prev && cur)
	{
		if (prev->data < cur->data
			&& !(prev->data == find_min(&list) && cur->data == find_max(&list)))
			return (0);
		prev = cur;
		cur = prev->next;
	}
	return (1);
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

char	*bases_sorted_way(t_list *list)
{
	t_list	*i;
	int 	grow;
	int 	degrow;

	i = list;
	grow = 0;
	degrow = 0;
	while (i->next)
	{
		if (i->data > i->next->data)
			degrow++;
		else
			grow++;
		i = i->next;
	}
	if ((degrow + grow) % 2 != 0)
		grow++;
	else
		degrow++;
	if (degrow > grow)
		return("degrow");
	else
		return("grow");
}


int	find_a_value(t_list *list, int min_or_max, int data, char *smaller_or_bigger)
{
	t_list *tmp;
	int pos;
	int	value_to_find;

	tmp = list;
	value_to_find = 0;
	while (tmp)
	{
		if (ft_strcmp(smaller_or_bigger, "smaller")
			&& tmp->data > min_or_max && tmp->data < data)
			value_to_find = tmp->data;
		else if (ft_strcmp(smaller_or_bigger, "bigger")
			&& tmp->data < min_or_max && tmp->data > data)
			value_to_find = tmp->data;
		tmp = tmp->next;
	}
	tmp = list;
	pos = 0;	
	while (tmp->data != value_to_find)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}
