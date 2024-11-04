/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:46:57 by marvin            #+#    #+#             */
/*   Updated: 2024/10/17 18:46:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int cond_peers_validity(int * conditions, int val_max)
{
	int box = 0;
	int peers = 0;
	while (box < val_max - 1)
	{
		peers = up_line_conds(box, val_max, conditions) \
		+ low_line_conds(box, val_max, conditions);
		if (peers < 3 || peers > val_max + 1)
			return (0);
		box++;
	}
	box = 0;
	while (!low_border(box, val_max))
	{
		peers = left_col_conds(box, val_max, conditions) \
		+ right_col_conds(box, val_max, conditions);
		if (peers < 3 || peers > val_max + 1)
			return (0);
		box += val_max;
		if (low_border(box, val_max))
		{
			peers = left_col_conds(box, val_max, conditions) \
			+ right_col_conds(box, val_max, conditions);
			if (peers < 3 || peers > val_max + 1)
				return (0);
		}
	}
	return (1);
}

int rev_line_check(int * conditions, int **answer, int box, int val_max)
{
	int if_vmax;
	int line;
	int towers_left;
	int save_case;

	save_case = box;
	if_vmax = 0;
	line = box / val_max;
	towers_left = val_max - (box % val_max + 1);
	while (box / val_max == line && box >= 0)
	{
		if (answer[0][box] == val_max)
			if_vmax = val_max - (box % val_max);
		box--;
	}
	if (if_vmax != 0)
	{
		if (if_vmax < right_col_conds(save_case, val_max, conditions))
			return (0);
	}
	else
		if (towers_left < right_col_conds(save_case, val_max, conditions))
			return (0);
	return (1);
}

int rev_col_check(int * conditions, int **answer, int box, int val_max)
{
	int if_vmax;
	int towers_left;
	int save_case;

	save_case = box;
	if_vmax = 0;
	towers_left = val_max - (box / val_max + 1);
	while (box / val_max >= 0 && box >= 0)
	{
		if (answer[0][box] == val_max)
			if_vmax =  val_max - (box / val_max);
		box -= val_max;
	}
	if (if_vmax != 0)
	{
		if (if_vmax < low_line_conds(save_case, val_max, conditions))
			return (0);
	}
	else
		if (towers_left < low_line_conds(save_case, val_max, conditions))
			return (0);
	return (1);
}

int	cross_opti(int *conditions, int box, int val_max)
{
	int box_limit;
	int pos_var;

	pos_var = ((box / val_max) + 1);//je dis a combien de box je suis de ma condition du haut
	if (pos_var >= up_line_conds(box, val_max, conditions))//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = up_line_conds(box, val_max, conditions);//je peux mettre ma val max
	box_limit = val_max - up_line_conds(box, val_max, conditions) + pos_var;//j'ajuste ma val max en fonction de ma case
	pos_var = ((box % val_max) + 1);//je dis a combien de box je suis de ma condition de gauche
	if (pos_var >= left_col_conds(box, val_max, conditions))//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = left_col_conds(box, val_max, conditions);//je peux mettre ma val max
	if (box_limit > (val_max - left_col_conds(box, val_max, conditions) + pos_var))//si ma val max d'avant est plus grande que la nouvelle
		box_limit = val_max - left_col_conds(box, val_max, conditions) + pos_var;//j'ajuste ma val max en prenant la plus petite
	pos_var = val_max - (box % val_max);//je dis a combien de box je suis de ma condition de droite
	if (pos_var >= right_col_conds(box, val_max, conditions))//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = right_col_conds(box, val_max, conditions);//je peux mettre ma val max
	if (box_limit > (val_max - right_col_conds(box, val_max, conditions) + pos_var))//si ma val max d'avant est plus grande que la nouvelle
		box_limit = val_max - right_col_conds(box, val_max, conditions) + pos_var;//j'ajuste ma val max en prenant la plus petite
	pos_var = val_max - (box / val_max);//je dis a combien de box je suis de ma condition du bas
	if (pos_var >= low_line_conds(box, val_max, conditions))//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = low_line_conds(box, val_max, conditions);//je peux mettre ma val max
	if (box_limit > (val_max - low_line_conds(box, val_max, conditions) + pos_var))//si ma val max d'avant est plus grande que la nouvelle
		box_limit = val_max - low_line_conds(box, val_max, conditions) + pos_var;//j'ajuste ma val max en prenant la plus petite
	return (box_limit);//je rends la limite la plus petite
}

/* la dans les optis j'ai :
- 1 fonction pour dire quelle valeur max je peux mettre en fonction des conditions de ma case
- 4 fonctions pour vérifier que je peux afficher le bon nombre de tours avant la val max ou non
- 3 fonctions pour vérifier que mes conditions sont valides
- 4 fonctions pour me dire si je suis sur une des bordures
- 4 fonctions "raccourcis", pour me donner la bonne condition sur la bonne bordure
- 1 fonction pour vérifier que je suis toujours sur la même ligne quand je veux vérifier mon nombre de tours dessus
- 2 fonctions d'affichage pour mettre les conditions autour et pour dire si mes valeurs sont cohérentes avec les conditions des lignes et des colonnes
- 1 fonction pour vérifier si j'ai des doublons
- 1 fonction pour dire si je peux placer ma val max sur une des bordures*/