/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:10:24 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:06 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	checker(int ac, char **av)
{
	t_list *a_list;
	t_list *b_list;

	a_list = initiate_a_list(ac, av);
	if (duplicates(a_list))
		error(RED"Error : duplicates !\n"RESET, a_list);
	if (sorted_a_list(a_list))
	{
		ft_printf("OK\n");
		free_list(a_list);
		return ;
	}
	b_list = NULL;
	check_list(a_list, b_list);
} */

void	c_error(char *msg, t_list *a_list, t_list *b_list)
{
	free_list(a_list);
	free_list(b_list);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	checker(int ac, char **av)
{
	t_list	*a_list;
	t_list	*b_list;

	a_list = initiate_a_list(ac, av);
	if (duplicates(a_list))
		error(RED"Error : duplicates !\n"RESET, a_list);
	b_list = NULL;
	check_list(a_list, b_list);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		checker(ac, av);
	return (0);
}
