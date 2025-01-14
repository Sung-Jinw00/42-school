/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:36:52 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	while (i < nmemb * size)
	{
		*(char *)(tab + i) = 0;
		i++;
	}
	return (tab);
}

void	init_vals(t_list *tmp, int *smaller_nb, int *bigger_nb)
{
	if (tmp->data < tmp->next->data)
	{
		*smaller_nb = tmp->data;
		*bigger_nb = tmp->next->data;
	}
	else
	{
		*smaller_nb = tmp->next->data;
		*bigger_nb = tmp->data;
	}
}

t_list	*r_or_rr(t_list **list, int len_list, int pos, char chosen_list)
{
	if (pos <= len_list / 2)
		while (pos-- > 0)
			ra_rb(list, chosen_list);
	else
	{
		pos = len_list - pos;
		while (pos-- > 0)
			rra_rrb(list, chosen_list);
	}
	return (*list);
}

void	if_is_max(t_list **a_list, int bigger_nb)
{
	int		pos;
	t_list	*tmp;

	tmp = *a_list;
	pos = 0;
	while (tmp && tmp->data != bigger_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	pos++;
	if (pos == len_list(*a_list))
		pos = 0;
	*a_list = r_or_rr(a_list, len_list(*a_list), pos, 'a');
}

void	if_is_min(t_list **a_list, int smaller_nb)
{
	int		pos;
	t_list	*tmp;

	tmp = *a_list;
	pos = 0;
	while (tmp && tmp->data != smaller_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	*a_list = r_or_rr(a_list, len_list(*a_list), pos, 'a');
}
