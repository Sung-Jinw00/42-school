/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:35:42 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/23 21:32:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int	cmp_dup_line(int **answer, int box, int val_max)
{
	int	compare;

	compare = box - 1;
	if (!left_border(box, val_max)) // si je ne suis pas au debut de la ligne
	{
		while (same_line(box, val_max, compare) && compare >= 0)
			// tant qu'on est pas a la fin de la ligne et que compare est pas en dessous de zero
		{
			if (answer[0][compare] == answer[0][box]) // si j'ai un doublon
				return (1);
			compare--;
		}
	}
	compare = box - val_max;
	if (!up_border(box, val_max)) // si je ne suis pas au debut de la colonne
	{
		while (compare >= 0) // tant qu'on est pas a la fin de la colonne
		{
			if (answer[0][compare] == answer[0][box]) // si j'ai un doublon
				return (1);
			compare -= val_max;
		}
	}
	return (0); // pas de doublons et affichage coherent
}

int	start_check(int *conditions, int **answer, int box, int val_max)
{
	if (cmp_dup_line(answer, box, val_max)) // on verifie si on a un doublon
		return (0);
	if (!visible_towers_in_line(answer, box, val_max, conditions)   
		// si j'affiche pas le bon nombre de tours
		|| !visible_towers_in_col(answer, box, val_max, conditions))
			// en lignes et en colonnes
		return (0);
	if (!rev_col_check(conditions, answer, box, val_max)     
		// si je peux theoriquement afficher suffisament
		|| !rev_line_check(conditions, answer, box, val_max))
			// de tours dans l'autre sens
		return (0);
	if ((low_border(box, val_max) && !visible_rev_towers_in_col(answer, box,
				val_max, conditions)) // idem dans l'autre sens
		|| (right_border(box, val_max) && !visible_rev_towers_in_line(answer,
				box, val_max, conditions)))
		return (0);
	return (1); // c'est coherent
}

// le tableau : r '2 2 1 3 2 1 2 4 2 3 2 5 2 2 1 2 1 4 2 3'
// display **answer@25

// 								la reponse : 1 3 4 2 3 4 2 1 4 2 1 3 2 1 3 4
// ce que mon programme trouve de juste :