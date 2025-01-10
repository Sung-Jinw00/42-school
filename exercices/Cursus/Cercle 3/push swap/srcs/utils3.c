/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/10 19:48:26 by locagnio         ###   ########.fr       */
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

int	pos_of_highest_value_in_chunk(t_list *b_list, int chunk)
{
	t_list	*tmp;
	int		highest_value;
	int		i;

	tmp = b_list;
	highest_value = tmp->data;
	tmp = tmp->next;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->chunk_level == chunk && tmp->data > highest_value)
			highest_value = tmp->data;
		tmp = tmp->next;
	}
	tmp = b_list;
	i = 0;
	while (tmp->data != highest_value)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
