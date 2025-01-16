/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:09:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 18:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int	up_line_conds(int box, int val_max, int *conditions)
		// selectionne la condition correspondante sur la ligne du haut
{
	return (conditions[box % val_max]);
}

int	low_line_conds(int box, int val_max, int *conditions)
		// selectionne la condition correspondante sur la ligne du bas
{
	return (conditions[val_max + box % val_max]);
}

int	left_col_conds(int box, int val_max, int *conditions)
		// selectionne la condition correspondante sur la ligne a gauche
{
	return (conditions[val_max * 2 + box / val_max]);
}

int	right_col_conds(int box, int val_max, int *conditions)
		// selectionne la condition correspondante sur la ligne a droite
{
	return (conditions[val_max * 3 + box / val_max]);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	return (result);
}