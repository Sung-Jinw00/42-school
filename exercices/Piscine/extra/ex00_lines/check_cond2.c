/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cond2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:57:57 by marvin            #+#    #+#             */
/*   Updated: 2024/10/20 23:21:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	visible_rev_towers_in_col(datas *params, int **answer, int box, int line)
		// on regarde si les tours affichables sont coherentes avec la condition du bas
{
	int j;
	int start_line;
	int compteur;

	start_line = line;
	j = start_line - 1;
	compteur = 1;
	while (answer[start_line][box] != params->val_max)
		// tant que je suis pas revenu a ma cases
	{
		if (answer[start_line][box] < answer[j][box])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_line = j;
		}
		j--;
	}
	if (answer[line][start_line] == params->val_max
		&& compteur != params->conditions[low_line_conds(box, params->val_max)])
		compteur = params->val_max * 2;
	return (compteur); // je rends le compteur
}

int	visible_rev_towers_in_line(datas *params, int **answer, int line)
		// on regarde si les tours affichables sont coherentes avec la condition de droite
{
	int j;
	int compteur;
	int start_line;

	start_line = params->val_max - 1; // pos actuelle - ecart du debut de ligne
	j = start_line - 1;
	compteur = 1;
	while (answer[line][start_line] != params->val_max)
		// tant que je suis pas revenu a ma cases
	{
		if (answer[line][start_line] < answer[line][j])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_line = j;
		}
		j--;
	}
	if (answer[line][start_line] == params->val_max
		&& compteur != params->conditions[right_col_conds(params->val_max
			* line, params->val_max)])
		compteur = params->val_max * 2;
	return (compteur); // je rends le compteur
}

int	visible_towers_in_col(datas *params, int **answer, int box, int line)
		// on regarde si les tours affichables sont coherentes avec la condition du haut
{
	int j;
	int start_col;
	int compteur;

	start_col = 0;
	j = start_col + 1;
	compteur = 1;
	while (start_col <= line && j <= line
		&& answer[start_col][box] != params->val_max)
		// tant que je suis pas revenu a ma cases
	{
		if (answer[start_col][box] < answer[j][box])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_col = j;
		}
		j++;
	}
	if (answer[start_col][box] == params->val_max
		&& compteur != params->conditions[up_line_conds(box, params->val_max)])
		compteur = params->val_max * 2;
	return (compteur); // je rends le compteur
}

int	visible_towers_in_line(datas *params, int **answer, int line)
		// on regarde si les tours affichables sont coherentes avec la condition de gauche
{
	int j;
	int compteur;
	int start_line;

	start_line = 0; // pos actuelle - ecart du debut de ligne
	j = start_line + 1;
	compteur = 1;
	while (answer[line][start_line] != params->val_max)
		// tant que je suis pas revenu a ma cases
	{
		if (answer[line][start_line] < answer[line][j])
			// si j'ai une tour plus grande que celle du debut
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			start_line = j;
		}
		j++;
	}
	if (answer[line][start_line] == params->val_max
		&& compteur != params->conditions[left_col_conds(params->val_max * line,
			params->val_max)])
		compteur = params->val_max * 2;
	return (compteur); // je rends le compteur
}