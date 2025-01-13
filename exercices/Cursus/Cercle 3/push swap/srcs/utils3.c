/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 18:14:54 by locagnio         ###   ########.fr       */
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

t_list	*r_or_rr(t_list **list, int len_list, int pos)
{
	if (pos <= len_list / 2)
		while (pos-- > 0)
			ra_rb(list, 'a');
	else
	{
		pos = len_list - pos;
		while (pos-- > 0)
			rra_rrb(list, 'a');
	}
	return (*list);
}

void	if_is_max(t_list **a_list, int bigger_nb)
{
	int pos;
	t_list *tmp;

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
	*a_list = r_or_rr(a_list, len_list(*a_list), pos);
}

void	if_is_min(t_list **a_list, int smaller_nb)
{
	int pos;
	t_list *tmp;

	tmp = *a_list;
	pos = 0;
	while (tmp && tmp->data != smaller_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	*a_list = r_or_rr(a_list, len_list(*a_list), pos);
}

t_list	*pos_of_value_for_b2(t_list **a_list, t_list *b_list, int bigger_nb)
{
	int pos;
	t_list	*tmp;

	tmp = *a_list;
	while (tmp)
	{
		if (tmp->data > b_list->data && tmp->data < bigger_nb)
			bigger_nb = tmp->data;
		tmp = tmp->next;
	}
	tmp = *a_list;
	pos = 0;
	while (tmp->data != bigger_nb)
	{
		tmp = tmp->next;
		pos++;
	}
	*a_list = r_or_rr(a_list, len_list(*a_list), pos);
	//print_vals_and_chunks(*a_list, b_list);
	return (*a_list);
}

void	init_sort_a(t_list *a_list, t_list **v1, t_list **v2, t_list **v3)
{
	*v1 = a_list;
	*v2 = (*v1)->next;
	*v3 = (*v2)->next;
}

void	sort_a(t_list **a_list)
{
	t_list	*v1;
	t_list	*v2;
	t_list	*v3;

	init_sort_a(*a_list, &v1, &v2, &v3);
	if (!sorted_list_grow(*a_list))
	{
		if (v1->data > v2->data && v2->data < v3->data
			&& !(v1->data == find_max(a_list) && v2->data == find_min(a_list)))
			sa_sb(a_list, 'a');
		else if (v1->data < v2->data && v2->data > v3->data
			&& !(v2->data == find_max(a_list) && v3->data == find_min(a_list)))
		{
			ra_rb(a_list, 'a');
			sa_sb(a_list, 'a');
		}
		else
			sa_sb(a_list, 'a');
		init_sort_a(*a_list, &v1, &v2, &v3);
	}
}

t_list	*lstdup(t_list *src)
{
	t_list	*cpy;
	t_list	*tmp;
	int		i;

	tmp = src;
	i = 0;
	cpy = NULL;
	while (tmp)
	{
		cpy = add_at(cpy, tmp->data, i);
		i++;
		tmp = tmp->next;
	}
	return (cpy);
}

int	get_at(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (!L || (pos > len_list(L)))
		return (-1);
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}
