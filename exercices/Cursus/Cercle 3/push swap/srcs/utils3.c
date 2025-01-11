/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/11 22:24:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	unsorted_grow(t_list *a_list)
{
	t_list *temp;
	int unsorted_pos;

	temp = a_list;
	unsorted_pos = 0;
	while (temp->next)
	{
		if (temp->data > temp->next->data && !temp->next->is_min)
			return (unsorted_pos);
		temp = temp->next;
		unsorted_pos++;
	}
	return (-1);
}

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

int	chunk_check(t_list *list, int first_chunk, int sec_chunk)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->chunk_level == first_chunk || tmp->chunk_level == sec_chunk)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_vals_and_chunks(t_list *a_list, t_list *b_list)
{
	t_list *tmp_a = a_list;
	t_list *tmp_b = b_list;
	int count = 1;
	ft_printf("-----------------------------       -----------------------------\n");
	ft_printf("|          liste a          |       |          liste b          |\n");
	ft_printf("-----------------------------       -----------------------------\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a && tmp_b)
		{
			ft_printf("data %d = %d     chunk level : %d  |  data %d = %d     chunk level : %d\n", count, tmp_a->data, tmp_a->chunk_level, count, tmp_b->data, tmp_b->chunk_level);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		else if (!tmp_a && tmp_b)
		{
			ft_printf("     N/A             N/A        |  data %d = %d     chunk level : %d\n", count, tmp_b->data, tmp_b->chunk_level);
			tmp_b = tmp_b->next;
		}
		else if (tmp_a && !tmp_b)
		{
			ft_printf("data %d = %d     chunk level : %d  |      N/A              N/A         \n", count, tmp_a->data, tmp_a->chunk_level);
			tmp_a = tmp_a->next;
		}
		else if (!tmp_a && !tmp_b)
			break ;
		count++;
	}
	ft_printf("\n");
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
	if (pos < len_list / 2)
		while (pos-- > 0)
			ra_rb(list, 'a');
	else if (pos > len_list / 2)
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
	if (pos + 1 == len_list(*a_list))
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

int	last_3_bnrs(t_list *a_list)
{
	int	i;
	t_list *tmp;

	i = 1;
	tmp = a_list;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == 3)
		return (1);
	return (0);
}

void	sort_a2(t_list **a_list)
{
	ra_rb(a_list, 'a');
	sa_sb(a_list, 'a');
	rra_rrb(a_list, 'a');
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
	if (!sorted_list(*a_list))
	{
		if (v1->data > v2->data && v2->data < v3->data
			&& !(v1->data == find_max(a_list) && v2->data == find_min(a_list)))
			sa_sb(a_list, 'a');
		else if (v1->data < v2->data && v2->data > v3->data
			&& !(v2->data == find_max(a_list) && v3->data == find_min(a_list)))
			sort_a2(a_list);
		else
		{
			sa_sb(a_list, 'a');
			rra_rrb(a_list, 'a');
		}
		init_sort_a(*a_list, &v1, &v2, &v3);
		while (!(v1->data < v2->data && v2->data < v3->data))
			ra_rb(a_list, 'a');
	}
}
