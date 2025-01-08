/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:08:07 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/08 17:58:52 by locagnio         ###   ########.fr       */
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
