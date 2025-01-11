/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:38:13 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/11 15:20:33 by locagnio         ###   ########.fr       */
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

int	sorted_list(t_list *list)
{
	t_list *prev;
	t_list *cur;

	prev = list;
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
