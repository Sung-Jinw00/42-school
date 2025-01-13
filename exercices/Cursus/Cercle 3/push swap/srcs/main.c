/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:11 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 18:01:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int ac, char **av)
{
	t_list *a_list;
	t_list *b_list;
	int len_a_list;

	a_list = initiate_a_list(ac, av);
	if (duplicates(a_list))
		error(RED"Error : duplicates !\n"RESET, a_list);
	if (sorted_a_list(a_list))
	{
		free_list(a_list);
		return ;
	}
	b_list = NULL;
	len_a_list = len_list(a_list);
	a_list = sort_list(a_list, b_list, len_a_list);
	free_list(a_list);
	free_list(b_list);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		push_swap(ac, av);
	return (0);
}
