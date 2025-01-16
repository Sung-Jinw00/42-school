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

int	up_line_conds(int cases, int val_max)
		// selectionne la condition correspondante sur la ligne du haut
{
	return (cases % val_max);
}

int	low_line_conds(int cases, int val_max)
		// selectionne la condition correspondante sur la ligne du bas
{
	return (val_max + cases % val_max);
}

int	left_col_conds(int cases, int val_max)
		// selectionne la condition correspondante sur la ligne a gauche
{
	return (val_max * 2 + cases / val_max);
}

int	right_col_conds(int cases, int val_max)
		// selectionne la condition correspondante sur la ligne a droite
{
	return (val_max * 3 + cases / val_max);
}

int	ft_strcmp(int s1, int s2)
{
	return (s1 - s2);
}