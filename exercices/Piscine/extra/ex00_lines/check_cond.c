/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:35:42 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/22 08:56:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* verifie si j'ai des doublons sur mes colonnes */
int cmp_dup_1col(int **answer, int line, int box, int cur_val)
{
	int	i;

	i = 0;
	while (i < line)
	{
		if (answer[i][box] == cur_val)
			return (1);
		i++;
	}
	return (0);
}

int cmp_dup_col(datas *params, int **answer, int line)
{
	int	i;
	int	j;
	int box;

	box = 0;
	i = 0;
	j = 1;
	while (box < params->val_max)
	{
		while (i < line)
		{
			while (j <= line)
			{
				if (answer[i][box] == answer[j][box])
					return (1);
				j++;
			}
			i++;
			j = i + 1;
		}
		box++;
		i = 0;
		j = 1;
	}
	return (0);
}

int check_t_nb_and_dupl(datas *params, int **answer, int line)
{
	int towers_left;
	int towers_right;
	int towers_col;
	int rev_towers_col;
	int box;

	if (cmp_dup_col(params, answer, line))//si j'ai un doublon sur ma ligne ou sur mes colonnes
		return (0);
	towers_left = visible_towers_in_line(params, answer, line);//on compte le nombre de tours qu'on affiche sur la ligne
	towers_right = visible_rev_towers_in_line(params, answer, line);//on compte le nombre de tours qu'on affiche sur la ligne
	if ((towers_left != params->conditions[left_col_conds(params->val_max * line, params->val_max)])
		|| (towers_right != params->conditions[right_col_conds(params->val_max * line, params->val_max)]))//si j'affiche trop de tours par rapport a la condition de gauche ou de droite
		return(0);
	box = 0;
	while (box < params->val_max)
	{
		towers_col = visible_towers_in_col(params, answer, box, line);//on compte le nombre de tours qu'on affiche sur la colonne
		if (towers_col > params->conditions[up_line_conds(box, params->val_max)])//si j'affiche trop de tours par rapport a la condition du haut
			return(0);
		if (line == params->val_max - 1)
		{
			rev_towers_col = visible_rev_towers_in_col(params, answer, box, line);//on compte le nombre de tours qu'on affiche sur la colonne
			if (rev_towers_col != params->conditions[low_line_conds(box, params->val_max)])//si j'affiche trop de tours par rapport a la condition du bas
				return(0);
		}
		box++;
	}
	return (1);//c'est coherent
}

/* verifie si ma premiere ligne est valide */
int check_conds(datas *params, int **answer, int line)
{
	int towers_left;
	int towers_right;

	towers_left = visible_towers_in_line(params, answer, line);//on compte le nombre de tours qu'on affiche sur la ligne
	towers_right = visible_rev_towers_in_line(params, answer, line);//on compte le nombre de tours qu'on affiche sur la ligne
	if ((towers_left != params->conditions[left_col_conds(0, params->val_max)])
		|| (towers_right != params->conditions[right_col_conds(0, params->val_max)]))//si j'affiche trop de tours par rapport a la condition de gauche ou du haut
		return(0);
	return (1);
}

int check_lines_bloc(datas *params, int **answer, int line)
{
	if (up_border(find_equiv_box(0, params->val_max, line), params->val_max) && check_conds(params, answer, line))//si je suis sur la bordure du haut
		return (1);//c'est bon
	else if (check_t_nb_and_dupl(params, answer, line))//si j'ai pas de doublon et que j'affiche le bon nombre de tours a gauche et en haut
		return (1);//c'est bon
	return (0);//c'est pas bon
}

//le tableau : r '2 2 1 3 2 1 2 4 2 3 2 5 2 2 1 2 1 4 2 3'
//display *answer@25


// 							 la reponse : 1 3 4 2 3 4 2 1 4 2 1 3 2 1 3 4
// ce que mon programme trouve de juste : 