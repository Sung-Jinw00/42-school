/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:08:07 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 21:48:12 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_natoi(const char *nptr, int *i, t_list *a_list)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		*i += 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -sign;
		*i += 1;
		if (!(nptr[*i] >= '0' && nptr[*i] <= '9'))
			error(RED"Error : Invalid arguments !\n"RESET, a_list);
	}
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		result = result * 10 + nptr[*i] - '0';
		*i += 1;
	}
	if (result < INT_MIN || result > INT_MAX)
		error(RED"Error : Number bigger than int !\n"RESET, a_list);
	return (result * sign);
}


long	len_list(t_list *list)
{
	long	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
