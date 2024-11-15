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

#include "r01boxs.h"

int	up_border(int box, int val_max)
{
	if (box / val_max == 0)
		return (1);//je suis sur la bordure du haut
	return (0);
}

int	low_border(int box, int val_max)
{
	if (box / val_max == val_max - 1)
		return (1);//je suis sur la bordure du bas
	return (0);
}

int	left_border(int box, int val_max)
{
	if (box % val_max == 0)
		return (1);//je suis sur la bordure de gauche
	return (0);
}

int	right_border(int box, int val_max)
{
	if (box % val_max == val_max -1)
		return (1);//je suis sur la bordure de droite
	return (0);
}

int same_line(int box, int val_max, int compare)
{
	if ((compare / val_max) == (box / val_max))
		return (1);//je suis sur la meme ligne
	return (0);	
}