/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefilling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:42:09 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 10:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

void one_or_val_max(int *conditions, int **answer, int val_max, int box, int *changes)
{
	if (up_line_conds(box, val_max, conditions) == val_max
		|| (low_line_conds(box, val_max, conditions) == val_max && box < val_max)
		|| left_col_conds(box, val_max, conditions) == val_max
		||  (right_col_conds(box, val_max, conditions) == val_max && box < val_max))
		vmax_in_cond(answer, val_max, box, changes, conditions);
	else if ((up_line_conds(box, val_max, conditions) == 1 && box < val_max)
		|| (low_line_conds(box, val_max, conditions) == 1 && box < val_max)
		||  left_col_conds(box, val_max, conditions) == 1
		||  right_col_conds(box, val_max, conditions) == 1
		|| up_line_conds(box, val_max, conditions) + low_line_conds(box, val_max, conditions) == val_max + 1
		|| left_col_conds(box, val_max, conditions) + right_col_conds(box, val_max, conditions) == val_max + 1)
		one_in_cond(answer, val_max, box, changes, conditions);
}

int check_if_soluce(int **answer, int val_max)
{
	int k;
	int box;

	k = 1;
	box = 0;
	while (box < val_max * val_max)
	{
		while (answer[0][box] != 0 && box < val_max * val_max)
			box++;
		while (k <= val_max)
			if (answer[k++][box] != 0 || box == val_max * val_max)
				return (1);
		box++;
		k = 1;
	}
	return (0);
}

void mini_pre_filling(int *conditions, int **answer, int val_max, int box)
{
	int changes;

	changes = 0;
	while (changes != 0)
	{
		changes = 0;
		if (up_border(box, val_max) || low_border(box, val_max)
			|| left_border(box, val_max) || right_border(box, val_max))
			one_or_val_max(conditions, answer, val_max, box, &changes);//pour afficher 5 ou 12345
		if (up_line_conds(box, val_max, conditions) == 2 || low_line_conds(box, val_max, conditions) == 2
			|| left_col_conds(box, val_max, conditions) == 2 || right_col_conds(box, val_max, conditions) == 2)
			two_in_cond(answer, val_max, box, &changes, conditions);//pour mettre ma val max si j'ai un 1 devant une condition qui vaut 2
		if (right_border(box, val_max) || low_border(box, val_max))
			last_digit(answer, val_max, box, &changes);//pour ecrire le dernier nombre possible si j'ai tous les autres chiffres sur une ligne
		if (answer[0][box] == 0 && one_possibility_left(answer, box, val_max))
			changes++;
		if_same_vals_line(answer, val_max, box, &changes);
		if_same_vals_col(answer, val_max, box, &changes);
		remove_invalid_values(answer, val_max, box);
	}
}

void pre_filling(int *conditions, int **answer, int val_max)
{
	int changes;
	int box;

	changes = 1;
	box = 0;
	limits(answer, conditions, val_max);
	while (changes != 0)
	{
		changes = 0;
		while (box < val_max * val_max)
		{
			if (up_border(box, val_max) || low_border(box, val_max)
				|| left_border(box, val_max) || right_border(box, val_max))
				one_or_val_max(conditions, answer, val_max, box, &changes);//pour afficher 5 ou 12345
			if (up_line_conds(box, val_max, conditions) == 2 || low_line_conds(box, val_max, conditions) == 2
				|| left_col_conds(box, val_max, conditions) == 2 || right_col_conds(box, val_max, conditions) == 2)
				two_in_cond(answer, val_max, box, &changes, conditions);//pour mettre ma val max si j'ai un 1 devant une condition qui vaut 2
			if (right_border(box, val_max) || low_border(box, val_max))
				last_digit(answer, val_max, box, &changes);//pour ecrire le dernier nombre possible si j'ai tous les autres chiffres sur une ligne
			if (answer[0][box] == 0 && one_possibility_left(answer, box, val_max))
				changes++;
			if_same_vals_line(answer, val_max, box, &changes);
			if_same_vals_col(answer, val_max, box, &changes);
			box++;
			while (answer[0][box] != 0 && box < val_max * val_max)
			{
				remove_invalid_values(answer, val_max, box);
				box++;
			}
		}
		box = 0;
		while (answer[0][box] != 0 && box < val_max * val_max)
			box++;
	}
}
