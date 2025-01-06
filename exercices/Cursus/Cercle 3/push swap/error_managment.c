/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:03:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 20:36:13 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	check_all_args(char **numbers)
{
	int j;
	int i;

	i = 0;
	j = 1;
	while (numbers[j])
	{
		while (numbers[j][i])
		{
			if (!(is_nb(numbers[j][i]) || numbers[j][i] == '+'
				|| numbers[j][i] == '-' || numbers[j][i] == ' '
				|| numbers[j][i] == '\t'))
				error(RED"Error : Invalid arguments !"RESET);
			i++;
		}
		j++;
	}
	return (0);
}
