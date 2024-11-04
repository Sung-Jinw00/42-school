/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:39:51 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 23:25:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str == 127)
			return (0);
		str++;
	}
	return (1);
}

int	assign_nb(char *av, int i)
{
	if (av[i] == '0')
		return (0);
	return (1);
}

void	assign_tens(char *av, int i, t_sss *datas, int j)
{
	datas[j].tens[0] = av[i];
	if (av[i] == '1')
		datas[j].tens[1] = av[i + 1];
	else if (av[i] == '0')
	{
		datas[j].tens[0] = '\0';
		datas[j].tens[1] = '\0';
	}
	else
		datas[j].tens[1] = '0';
}

void	assign_hundred(t_sss *datas, int j)
{
	datas[j].hundred[0] = '1';
	datas[j].hundred[1] = '0';
	datas[j].hundred[2] = '0';
}
