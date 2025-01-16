/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meilleur_affichage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:02:03 by marvin            #+#    #+#             */
/*   Updated: 2024/10/17 16:02:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

void	write_conds(int *conditions, int bordure, int box, int val_max)
{
	char	cond;

	while (bordure == 1 && box < val_max)
	{
		if (box == 0)
			write(1, "   ", 3);
		cond = 48 + up_line_conds(box++, val_max, conditions);
		write(1, &cond, 1);
		write(1, " ", 1);
		if (box == val_max)
			write(1, "\n", 1);
	}
	while (bordure == 2 && box < val_max)
	{
		if (box == 0)
			write(1, "\n   ", 4);
		cond = 48 + low_line_conds(box++, val_max, conditions);
		write(1, &cond, 1);
		write(1, " ", 1);
	}
	if (bordure == 3 && box < val_max * val_max)
	{
		cond = 48 + left_col_conds(box, val_max, conditions);
		write(1, &cond, 1);
		write(1, "  ", 2);
		return ;
	}
	if (bordure == 4 && box < val_max * val_max)
	{
		write(1, "  ", 2);
		cond = 48 + right_col_conds(box, val_max, conditions);
		write(1, &cond, 1);
		return ;
	}
	write(1, "\n", 1);
}

#include <stdio.h>

int	visible_rev_towers_in_col_final(int val_max, int *conditions, int **answer,
		int box)
		// on regarde si les tours affichables sont coherentes avec la condition du bas
{
	int j;
	int start_col;
	int compteur;

	start_col = ((val_max - 1) * val_max) + (box % val_max);
	j = start_col - val_max;
	compteur = 1;
	while (answer[0][start_col] != val_max && j >= 0)
		// tant que je suis pas revenu a ma cases
	{
		if (answer[0][start_col] < answer[0][j])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_col = j;
		}
		j -= val_max;
	}
	if (answer[0][start_col] == val_max && compteur != low_line_conds(box,
			val_max, conditions))
		compteur = val_max * 2;
	return (compteur); // je rends le compteur
}

int	visible_rev_towers_in_line_final(int val_max, int *conditions, int **answer,
		int box)
		// on regarde si les tours affichables sont coherentes avec la condition de droite
{
	int j;
	int compteur;
	int start_line;

	start_line = (box / val_max) * val_max + (val_max - 1); // pos actuelle
		- ecart du debut de ligne
	j = start_line - 1;
	compteur = 1;
	while (answer[0][start_line] != val_max)
		// tant que je suis pas revenu a ma cases
	{
		if (answer[0][start_line] < answer[0][j])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_line = j;
		}
		j--;
	}
	if (answer[0][start_line] == val_max && compteur != right_col_conds(box,
			val_max, conditions))
		compteur = val_max * 2;
	return (compteur); // je rends le compteur
}

int	visible_towers_in_col_final(int val_max, int *conditions, int **answer,
		int box)
		// on regarde si les tours affichables sont coherentes avec la condition du haut
{
	int j;
	int start_col;
	int compteur;

	start_col = box % val_max;
	j = start_col + val_max;
	compteur = 1;
	while (answer[0][start_col] != val_max && j < val_max * val_max)
		// tant que je suis pas revenu a ma cases
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
	if (answer[0][start_col] == val_max && compteur != up_line_conds(box,
			val_max, conditions))
		compteur = val_max * 2;
	return (compteur); // je rends le compteur
}

int	visible_towers_in_line_final(int val_max, int *conditions, int **answer,
		int box)
		// on regarde si les tours affichables sont coherentes avec la condition de gauche
{
	int j;
	int compteur;
	int start_line;

	start_line = (box / val_max) * val_max; // pos actuelle
		- ecart du debut de ligne
	j = start_line + 1;
	compteur = 1;
	while (answer[0][start_line] != val_max)
		// tant que je suis pas revenu a ma cases
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
	if (answer[0][start_line] == val_max && compteur != left_col_conds(box,
			val_max, conditions))
		compteur = val_max * 2;
	return (compteur); // je rends le compteur
}

void	verif_conds(int **answer, int val_max, int *conditions)
{
	int	towers_left;
	int	towers_right;
	int	towers_up;
	int	towers_down;
	int	line;
	int	col;
	int	box;

	for (box = 0; box < val_max * val_max; box++)
	{
		line = box / val_max + 1;
		col = box % val_max + 1;
		if (cmp_dup_line(answer, box, val_max)) // on verifie si on a un doublon
		{
			printf("doublon(s) sur une colonne\n\n");
			return ;
		}
		towers_left = visible_towers_in_line_final(val_max, conditions, answer,
				box);
		towers_right = visible_rev_towers_in_line_final(val_max, conditions,
				answer, box);
		towers_up = visible_towers_in_col_final(val_max, conditions, answer,
				box);
		towers_down = visible_rev_towers_in_col_final(val_max, conditions,
				answer, box);
		if ((towers_left != left_col_conds(box, val_max, conditions))
			|| (towers_right != right_col_conds(box, val_max, conditions)))
		{
			printf("nombre de tours sur la ligne %d incorrect.\n\n", line);
			return ;
		}
		if ((towers_up != up_line_conds(box, val_max, conditions))
			|| (towers_down != low_line_conds(box, val_max, conditions)))
		{
			printf("nombre de tours sur sur la colonne %d incorrect.\n\n", col);
			return ;
		}
	}
	printf("Tout est bon ! Yey :3 !\n\n");
}
