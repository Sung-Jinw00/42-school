/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:06:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 18:06:47 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list, char *msg)
{
	ft_printf("%s", msg);
	while (list)
	{
		ft_printf("%d ", list->data);
		list = list->next;
	}
	ft_printf("\n");
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
