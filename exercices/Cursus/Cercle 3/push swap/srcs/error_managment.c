/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:03:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:42:19 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *msg, t_list *a_list)
{
	free_list(a_list);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	check_all_args(char **numbers)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (numbers[j])
	{
		while (numbers[j][i])
		{
			if (!(is_nb(numbers[j][i]) || numbers[j][i] == '+'
					|| numbers[j][i] == '-' || numbers[j][i] == ' '
					|| numbers[j][i] == '\t'))
				error(RED "Error : Invalid arguments !\n" RESET, NULL);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	duplicates(t_list *list)
{
	t_list	*i;
	t_list	*j;

	j = list;
	i = j->next;
	while (j)
	{
		i = j->next;
		while (i)
		{
			if (j->data == i->data)
				return (1);
			i = i->next;
		}
		j = j->next;
	}
	return (0);
}
