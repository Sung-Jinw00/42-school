/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:21:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 18:21:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	up_border(int cases, int val_max)
{
	if (cases / val_max == 0)
		return (1); // je suis sur la bordure du haut
	return (0);
}

int	low_border(int cases, int val_max)
{
	if (cases / val_max == val_max - 1)
		return (1); // je suis sur la bordure du bas
	return (0);
}

int	left_border(int cases, int val_max)
{
	if (cases % val_max == 0)
		return (1); // je suis sur la bordure de gauche
	return (0);
}

int	right_border(int cases, int val_max)
{
	if (cases % val_max == val_max - 1)
		return (1); // je suis sur la bordure de droite
	return (0);
}

int	find_equiv_box(int box, int val_max, int line)
{
	return ((box % val_max) + (val_max * line));
}