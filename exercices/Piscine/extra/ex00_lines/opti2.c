/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:22:13 by marvin            #+#    #+#             */
/*   Updated: 2024/10/19 12:22:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int *ft_calloc(int *tab, int size)
{
	int i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return(NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int cond_peers_validity(int * conditions, int val_max)
{
	int cases = 0;
	int peers = 0;
	while (cases < val_max - 1)
	{
		peers = conditions[up_line_conds(cases, val_max)] \
		+ conditions[low_line_conds(cases, val_max)];
		if (peers < 3 || peers > val_max + 1)
			return (0);
		cases++;
	}
	cases = 0;
	while (!low_border(cases, val_max))
	{
		peers = conditions[left_col_conds(cases, val_max)] \
		+ conditions[right_col_conds(cases, val_max)];
		if (peers < 3 || peers > val_max + 1)
			return (0);
		cases += val_max;
		if (low_border(cases, val_max))
		{
			peers = conditions[left_col_conds(cases, val_max)] \
			+ conditions[right_col_conds(cases, val_max)];
			if (peers < 3 || peers > val_max + 1)
				return (0);
		}
	}
	return (1);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	if_charset(int val, int *charset, int k)
{
	int	j;

	j = 0;
	while (charset[j] && j < k)
	{
		if (val == charset[j])
			return (1);
		j++;
	}
	return (0);
}