/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:06:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:40:07 by locagnio         ###   ########.fr       */
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

static void	print_vals2(t_list *tmp_a, t_list *tmp_b, int count)
{
	if (!tmp_a && tmp_b)
	{
		ft_printf("     N/A      |  data %d = %d\n", count, tmp_b->data);
		tmp_b = tmp_b->next;
	}
	else if (tmp_a && !tmp_b)
	{
		ft_printf("data %d = %d  |     N/A      \n", count, tmp_a->data);
		tmp_a = tmp_a->next;
	}
}

void	print_vals(t_list *a_list, t_list *b_list)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		count;

	count = 1;
	tmp_a = a_list;
	tmp_b = b_list;
	ft_printf("-----------   -----------\n| liste a |   | liste b |\n");
	ft_printf("-----------   -----------\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a && tmp_b)
		{
			ft_printf("data %d = %d  |  data %d = %d\n", count, tmp_a->data, \
			count, tmp_b->data);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		else if ((!tmp_a && tmp_b) || (tmp_a && !tmp_b))
			print_vals2(tmp_a, tmp_b, count);
		else if (!tmp_a && !tmp_b)
			break ;
		count++;
	}
	ft_printf("\n");
}
