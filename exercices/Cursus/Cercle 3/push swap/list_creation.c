/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:00:51 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 20:01:33 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cell	*create_cell(int data)
{
	t_cell	*t_cell;

	t_cell = malloc(sizeof(t_cell));
	if (!t_cell)
		return (NULL);
	t_cell->data = data;
	t_cell->next = NULL;
	return (t_cell);
}

t_list	*add_at(t_list *L, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_cell	*t_cell;

	cur = L;
	t_cell = create_cell(data);
	if (!L)
		return (t_cell);
	else if (pos == 0)
	{
		t_cell->next = L;
		return (t_cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = t_cell;
	t_cell->next = cur;
	return (L);
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
			list = add_at(list, ft_natoi(av[1], &i), count++);
	}
	else if (ac > 2 && !check_all_args(av))
	{
		while (av[j])
		{
			while (i < (int)ft_strlen(av[j]))
				list = add_at(list, ft_natoi(av[j], &i), count++);
			i = 0;
			j++;
		}
	}
	return (list);
}
