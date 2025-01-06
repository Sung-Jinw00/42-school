/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:38:13 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 21:28:24 by locagnio         ###   ########.fr       */
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
	ft_printf("%s", action);
	if (chosen_list == 'a')
		ft_printf("a\n");
	else
		ft_printf("b\n");
}