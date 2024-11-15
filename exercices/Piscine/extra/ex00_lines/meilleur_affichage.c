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

#include "lib.h"

void	write_conds(int *conditions, int bordure, int cases, int val_max)
{
	char cond;

	while (bordure == 1 && cases < val_max)
	{
		if (cases == 0)
			write (1, "   ", 3);
		cond = 48 + conditions[up_line_conds(cases++, val_max)];
		write (1, &cond, 1);
		write (1, " ", 1);
		if (cases == val_max)
			write (1, "\n", 1);
	}
	while (bordure == 2 && cases < val_max)
	{
		if (cases == 0)
			write (1, "\n   ", 4);
		cond = 48 + conditions[low_line_conds(cases++, val_max)];
		write (1, &cond, 1);
		write (1, " ", 1);
	}
	if (bordure == 3 && cases < val_max)
	{
		cond = 48 + conditions[left_col_conds(cases * val_max, val_max)];
		write (1, &cond, 1);
		write (1, "  ", 2);
		return ;
	}
	if (bordure == 4 && cases < val_max)
	{
		write (1, "  ", 2);
		cond = 48 + conditions[right_col_conds(cases * val_max, val_max)];
		write (1, &cond, 1);
		return ;
	}
	write (1, "\n", 1);
}

#include <stdio.h>

void	verif_conds(datas *params, int **answer, int line)
{
	int towers_left;
	int towers_right;
	int towers_col;
	int rev_towers_col;
	int box;

	if (cmp_dup_col(params, answer, line))//si j'ai un doublon sur mes colonnes
	{
		printf("doublon(s) sur une colonne\n\n");
		return ;
	}
	for (line = 0; line < params->val_max; line++)
	{
		towers_left = visible_towers_in_line(params, answer, line);//on compte le nombre de tours qu'on affiche sur la ligne
		towers_right = visible_rev_towers_in_line(params, answer, line);//on compte le nombre de tours qu'on affiche sur la ligne
		if ((towers_left != params->conditions[left_col_conds(params->val_max * line, params->val_max)])
		|| (towers_right != params->conditions[right_col_conds(params->val_max * line, params->val_max)]))//si j'affiche trop de tours par rapport a la condition de gauche ou de droite
	{
			printf("nombre de tours sur la ligne %d incorrect.\n\n", line + 1);
			return ;
		}
		for (box = 0; box < params->val_max; box++)
		{
			if (answer[line][box] == params->val_max)
			{
				towers_col = visible_towers_in_col(params, answer, box, line);//on compte le nombre de tours qu'on affiche sur la colonne
				if (towers_col != params->conditions[up_line_conds(box, params->val_max)])//si j'affiche trop de tours par rapport a la condition du haut
				{
					printf("nombre de tours sur sur la colonne %d incorrect.\n\n", line + 1);
					return ;
				}
			}
			if (line == params->val_max - 1)
			{
				rev_towers_col = visible_rev_towers_in_col(params, answer, box, line);//on compte le nombre de tours qu'on affiche sur la colonne
			if (rev_towers_col != params->conditions[low_line_conds(box, params->val_max)])//si j'affiche trop de tours par rapport a la condition du bas
			{
					printf("nombre de tours sur dans l'autre sens a la colonne %d incorrect.\n\n", line + 1);
					return ;
				}
			}
		}
	}
	printf("Tous est bon ! Yey :3 !\n\n");
}
