/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cond2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:57:57 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 21:25:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int	visible_rev_towers_in_col(int **answer, int box, int val_max,
		int *conditions)
{
	int	rev_col;
	int	compteur;

	rev_col = box - val_max;
	compteur = 1;
	while (answer[0][box] != val_max && rev_col / val_max >= 0)
		// tant que je suis pas arrive a 9
	{
		if (answer[0][box] < answer[0][rev_col])
			// si j'ai une tour plus grande que celle de depart
		{
			compteur++; // j'augmente le compteur du tours
			box = rev_col;
		}
		rev_col -= val_max;
	}
	if (compteur == low_line_conds(box, val_max, conditions))
		return (1);
	return (0);
}

int	visible_rev_towers_in_line(int **answer, int box, int val_max,
		int *conditions)
{
	int	rev_line;
	int	compteur;

	rev_line = box - 1;
	compteur = 1;
	while (answer[0][box] != val_max && rev_line % val_max >= 0)
		// tant que je suis pas arrive a 9
	{
		if (answer[0][box] < answer[0][rev_line])
			// si j'ai une tour plus grande que celle du depart
		{
			compteur++;     // j'augmente le compteur de tours
			box = rev_line; // je regarde plus loin
		}
		rev_line--;
	}
	if (compteur == right_col_conds(box, val_max, conditions))
		return (1);
	return (0);
}

int	visible_towers_in_col(int **answer, int box, int val_max, int *conditions)
{
	int	j;
	int	compteur;
	int	start_col;

	start_col = box - ((box / val_max) * val_max); // pos actuelle
		- ecart du debut de colonne
	j = start_col + val_max;
	compteur = 1;
	while (answer[0][j] != 0 && j < val_max * val_max
		&& answer[0][start_col] != val_max)
		// tant que je suis pas revenu a ma box
	{
		if (answer[0][start_col] < answer[0][j])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_col = j;
		}
		j += val_max;
	}
	if (answer[0][start_col] != val_max && compteur < up_line_conds(box,
			val_max, conditions))
		return (1);
	else if (answer[0][start_col] == val_max && compteur == up_line_conds(box,
			val_max, conditions))
		return (1);
	return (0);
}

int	visible_towers_in_line(int **answer, int box, int val_max, int *conditions)
{
	int	j;
	int	compteur;
	int	start_line;

	start_line = box - (box % val_max); // pos actuelle
		- ecart du debut de ligne
	j = start_line + 1;
	compteur = 1;
	while (answer[0][j] != 0 && j < (box - (box % val_max) + val_max)
		&& answer[0][start_line] != val_max)
		// tant que je suis pas revenu a ma box
	{
		if (answer[0][start_line] < answer[0][j])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_line = j;
		}
		j++;
	}
	if (answer[0][start_line] != val_max && compteur < left_col_conds(box,
			val_max, conditions))
		return (1);
	else if (answer[0][start_line] == val_max && compteur == left_col_conds(box,
			val_max, conditions))
		return (1);
	return (0);
}

int	above_cond(int **answer, int box, int val_max, int *conditions)
{
	int	limit_line;
	int	limit_col;

	limit_line = val_max - left_col_conds(box, val_max, conditions) + 1;
	limit_col = val_max - up_line_conds(box, val_max, conditions) + 1;
	if (limit_line < (answer[0][box] - (box % val_max))
		|| limit_col < (answer[0][box] - (box / val_max)))
		return (0);
	return (1);
}
