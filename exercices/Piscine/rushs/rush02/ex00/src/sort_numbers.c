/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:06:09 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 22:35:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_struct(int i, t_sss *datas, char *av)
{
	int	n;
	int	amount;

	n = 0;
	while ((datas[0].len - n) % 3 != 0)
		n++;
	amount = n;
	if (amount == 0)
	{
		datas[0].hund_nb[0] = av[i++] * assign_nb(av, 0);
		if (datas[0].hund_nb[0] != 0)
			assign_hundred(datas, 0);
		amount = 2;
	}
	if (amount == 2)
	{
		assign_tens(av, i++, datas, 0);
		if (av[i - 1] == '1' || (av[i - 1] != '1' && av[i] == '0'))
			datas[0].unit[0] = '\0';
		else
			datas[0].unit[0] = av[i];
	}
	else if (amount == 1)
		datas[0].unit[0] = av[i];
	return (i + n);
}

t_sss	*build_struct(int i, t_sss *datas, char *av)
{
	int	j;

	j = 1;
	while (i < datas[0].len)
	{
		datas[j].hund_nb[0] = av[i] * assign_nb(av, i);
		if (datas[j].hund_nb[0] != 0)
			assign_hundred(datas, j);
		assign_tens(av, i + 1, datas, j);
		if (av[i + 1] == '1' || (av[i + 1] != '1' && av[i + 2] == '0'))
			datas[j].unit[0] = '\0';
		else
			datas[j].unit[0] = av[i + 2];
		datas[j].len = datas[0].len - i;
		i += 3;
		j++;
	}
	return (datas);
}

t_sss	*sort_numbers(char *av)
{
	int		i;
	t_sss	*datas;
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (av[len])
		len++;
	datas = malloc(sizeof(t_sss) * (len / 3));
	datas[0].len = len;
	i = init_struct(0, datas, av) + 1;
	datas = build_struct(i, datas, av);
	datas[(len - 1) / 3 + 1].hund_nb[0] = '\0';
	datas[(len - 1) / 3 + 1].hundred[0] = '\0';
	datas[(len - 1) / 3 + 1].tens[0] = '\0';
	datas[(len - 1) / 3 + 1].unit[0] = '\0';
	datas[(len - 1) / 3 + 1].len = 0;
	return (datas);
}
