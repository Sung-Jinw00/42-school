/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:00:51 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/11 16:09:13 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cell	*create_cell(int data)
{
	t_cell	*cell;

	cell = ft_calloc(1, sizeof(t_list));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

t_list	*add_at(t_list *list, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_cell	*cell;

	cur = list;
	cell = create_cell(data);
	if (!cell)
		error(RED"Error : issue creating cell.\n"RESET, list);
	if (!list)
		return (cell);
	else if (pos == 0)
	{
		cell->next = list;
		return (cell);
	}
	i = 0;
	while (i++ < pos)
	{
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (list);
}

t_list	*initiate_a_list(int ac, char **av)
{
	t_list *list;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 1;
	count = 0;
	list = NULL;
	if (ac == 2 && !check_all_args(av))
	{
		while (i < (int)ft_strlen(av[1]))
			list = add_at(list, ft_natoi(av[1], &i, list), count++);
	}
	else if (ac > 2 && !check_all_args(av))
	{
		while (av[j])
		{
			while (i < (int)ft_strlen(av[j]))
				list = add_at(list, ft_natoi(av[j], &i, list), count++);
			i = 0;
			j++;
		}
	}
	return (list);
}

int	find_min(t_list **a_list)
{
	int 	min;
	t_list *tmp;

	tmp = *a_list;
	tmp->is_min = 0;
	min = tmp->data;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp->is_min = 0;
		tmp = tmp->next;
	}
	tmp = *a_list;
	while (tmp->data != min)
		tmp = tmp->next;
	tmp->is_min = 1;
	return (tmp->data);
}

int	find_max(t_list **a_list)
{
	int 	max;
	t_list *tmp;

	tmp = *a_list;
	tmp->is_max = 0;
	max = tmp->data;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp->is_max = 0;
		tmp = tmp->next;
	}
	tmp = *a_list;
	while (tmp->data != max)
		tmp = tmp->next;
	tmp->is_max = 1;
	return (tmp->data);
}
