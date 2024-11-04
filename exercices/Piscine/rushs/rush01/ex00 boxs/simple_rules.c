/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:58:16 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 08:58:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

void	two_and_one_in_cond(int **answer, int val_max, int box, int *changes, int *conditions)
{
	int new_nb;
	int trigger;

	new_nb = 0;
	trigger = 0;
	if (up_border(box, val_max) && answer[0][box] == val_max && low_line_conds(box, val_max, conditions) == 2
		&& answer[0][box + (val_max * (val_max - 1))] != val_max - 1)//si je suis sur la bordure du haut et que j'ai un 2 en conditions du bas
	{
		new_nb = box + (val_max * (val_max - 1));
		trigger++;
	}
	if (left_border(box, val_max) && answer[0][box] == val_max && right_col_conds(box, val_max, conditions) == 2
		&& answer[0][box + val_max - 1] != val_max - 1)//si je suis sur la bordure de gauche et que j'ai un 2 en conditions de droite
	{
		new_nb = box + val_max - 1;
		trigger++;
	}
	if (right_border(box, val_max) && answer[0][box] == val_max && left_col_conds(box, val_max, conditions) == 2
		&& answer[0][box - (val_max - 1)] != val_max - 1)//si je suis sur la bordure de droite et que j'ai un 2 en conditions de gauche
	{
		new_nb = box - (val_max - 1);
		trigger++;
	}
	if (low_border(box, val_max) && answer[0][box] == val_max && up_line_conds(box, val_max, conditions) == 2
		&& answer[0][box - (val_max * (val_max - 1))] != val_max - 1)//si je suis sur la bordure du bas et que j'ai un 2 en conditions du haut
	{
		new_nb = box - (val_max * (val_max - 1));
		trigger++;
	}
	if (trigger == 1)
	{
		answer[0][new_nb] = val_max - 1;//je met ma val_max -1 en bas pour remplir la condition
		remove_invalid_values(answer, val_max, new_nb);
		(*changes)++;
	}
}

void	vmax_in_cond(int **answer, int val_max, int box, int *changes, int *conditions)
{
	if (up_line_conds(box, val_max, conditions) == val_max
		|| low_line_conds(box, val_max, conditions) == val_max)//si j'ai val_max en condition en haut ou en bas
	
	{	if (up_line_conds(box, val_max, conditions) == val_max)
			one_to_5_in_col(answer, val_max, box, "up");
		if (low_line_conds(box, val_max, conditions) == val_max)
			one_to_5_in_col(answer, val_max, box, "down");
		(*changes)++;
	}
	if (right_col_conds(box, val_max, conditions) == val_max
		|| left_col_conds(box, val_max, conditions) == val_max)//si j'ai val_max en condition de droite ou de gauche
	{
		if (right_col_conds(box, val_max, conditions) == val_max)
			one_to_5_in_line(answer, val_max, box, "right");
		if (left_col_conds(box, val_max, conditions) == val_max)
			one_to_5_in_line(answer, val_max, box, "left");
		(*changes)++;
	}
}

void	one_in_cond2(int **answer, int val_max, int *box, int *changes, int *conditions)
{
	if ((low_line_conds(*box, val_max, conditions) == 1 && *box < val_max
		&& answer[0][*box + val_max * (val_max - 1)] != val_max)
		|| (right_col_conds(*box, val_max, conditions) == 1 && left_border(*box, val_max)
		&& answer[0][*box + (val_max - 1)] != val_max))
	{
		if (low_line_conds(*box, val_max, conditions) == 1)
			*box += val_max * (val_max - 1);
		else if (right_col_conds(*box, val_max, conditions))
			*box += (val_max - 1);
		if (answer[0][*box] != val_max)
		{
			answer[0][*box] = val_max;
			remove_invalid_values(answer, val_max, *box);
			(*changes)++;
		}
	}
	else if ((up_line_conds(*box, val_max, conditions) + low_line_conds(*box, val_max, conditions) == val_max + 1
		&& up_border(*box, val_max) && answer[0][*box + val_max * (up_line_conds(*box, val_max, conditions) - 1)] != val_max)
		|| (left_col_conds(*box, val_max, conditions) + right_col_conds(*box, val_max, conditions) == val_max + 1
		&& left_border(*box, val_max) && answer[0][*box + left_col_conds(*box, val_max, conditions) - 1] != val_max))
	{
		if (up_border(*box, val_max))
		{
			*box += val_max * (up_line_conds(*box, val_max, conditions) - 1);
			answer[0][*box] = val_max;
		}
		else
		{
			*box += left_col_conds(*box, val_max, conditions) - 1;
			answer[0][*box] = val_max;
		}
		remove_invalid_values(answer, val_max, *box);
		(*changes)++;
	}
}

void	one_in_cond(int **answer, int val_max, int box, int *changes, int *conditions)
{
	if (up_line_conds(box, val_max, conditions) == 1
		&& (answer[0][box] != val_max) && box < val_max)
	{
		answer[0][box] = val_max;
		remove_invalid_values(answer, val_max, box);
		(*changes)++;
	}
	else if (left_col_conds(box, val_max, conditions) == 1 && left_border(box, val_max)
		&& (answer[0][box] != val_max))
	{
		answer[0][box] = val_max;
		remove_invalid_values(answer, val_max, box);
		(*changes)++;
	}
	else
		one_in_cond2(answer, val_max, &box, changes, conditions);
	two_and_one_in_cond(answer, val_max, box, changes, conditions);
}

int	four_is_placable(int **answer, int box, int val_max, char *da_wae)
{
	int end_line;

	end_line = box;
	if (!ft_strcmp(da_wae, "right"))//si j'ai val_max en condition du bas, j'ecris val_max...321 sur ma colonne
	{
		while (end_line % val_max != 0)
		{
			end_line--;
			if (answer[val_max - 1][end_line] == val_max - 1)
				return (1);
		}
	}
	else if (!ft_strcmp(da_wae, "left"))//si j'ai val_max en condition du bas, j'ecris val_max...321 sur ma colonne
	{
		while (end_line % val_max != val_max - 1)
		{
			end_line++;
			if (answer[val_max - 1][end_line] == val_max - 1)
				return (1);
		}
	}
	else if (!ft_strcmp(da_wae, "up"))//si j'ai val_max en condition du bas, j'ecris val_max...321 sur ma colonne
	{
		while (end_line / val_max != val_max - 1)
		{
			end_line += val_max;
			if (answer[val_max - 1][end_line] == val_max - 1)
				return (1);
		}
	}
	else if (!ft_strcmp(da_wae, "down"))//si j'ai val_max en condition du bas, j'ecris val_max...321 sur ma colonne
	{
		while (end_line / val_max != 0)
		{
			end_line -= val_max;
			if (answer[val_max - 1][end_line] == val_max - 1)
				return (1);
		}
	}
	return (0);
}

void	two_in_cond_up(int **answer, int val_max, int box, int *changes)
{
	int away;
	int i;

	away = 0;
	i = 1;
	if (box / val_max == 1 && answer[0][box - val_max] == 1)
	{
		answer[0][box] = val_max;
		remove_invalid_values(answer, val_max, box);
		(*changes)++;
	}
	else if (box / val_max > 1 && box / val_max != val_max - 1 && answer[0][box] == val_max)
	{
		if (!four_is_placable(answer, box, val_max, "up"))
		{
			box = box % val_max;
			answer[0][box] = val_max - 1;
			remove_invalid_values(answer, val_max, box);
			(*changes)++;
		}
		else
		{
			away = (box / val_max - 1);//l'ecart de cases
			while (i <= away)
				answer[i++][box % val_max] = 0;
		}
	}
}

void	two_in_cond_low(int **answer, int val_max, int box, int *changes)
{
	int away;
	int i;

	away = 0;
	i = 1;
	if (answer[0][box] == 1 && low_border(box, val_max))
	{
		box -= val_max;
		answer[0][box] = val_max;
		remove_invalid_values(answer, val_max, box);
		(*changes)++;
	}
	else if (box / val_max < val_max - 2 && box / val_max != 0 && answer[0][box] == val_max)
	{
		if (!four_is_placable(answer, box, val_max, "down"))
		{
			box = box % val_max + val_max * (val_max - 1);
			answer[0][box] = val_max - 1;
			remove_invalid_values(answer, val_max, box);
			(*changes)++;
		}
		else
		{
			away = (val_max - 1 - (box / val_max + 1));//l'ecart de cases
			while (i <= away)
				answer[i++][(box % val_max) + val_max * (val_max - 1)] = 0;
		}
	}
}

void	two_in_cond_left(int **answer, int val_max, int box, int *changes)
{
	int away;
	int i;

	away = 0;
	i = 1;
	if (box % val_max == 1 && answer[0][box - 1] == 1)
	{
		answer[0][box] = val_max;
		remove_invalid_values(answer, val_max, box);
		(*changes)++;
	}
	else if (box % val_max > 1 && box % val_max != val_max - 1 && answer[0][box] == val_max)
	{
		if (!four_is_placable(answer, box, val_max, "left"))
		{
			box -= box % val_max;
			answer[0][box] = val_max - 1;
			remove_invalid_values(answer, val_max, box);
			(*changes)++;
		}
		else
		{
			away = (box % val_max - 1);//l'ecart de cases
			while (i <= away)
				answer[i++][box - (box % val_max)] = 0;
		}
	}
}

void	two_in_cond_right(int **answer, int val_max, int box, int *changes)
{
	int away;
	int i;

	away = 0;
	i = 1;
	if (answer[0][box] == 1 && right_border(box, val_max))
	{
		box--;
		answer[0][box] = val_max;
		remove_invalid_values(answer, val_max, box);
		(*changes)++;
	}
	else if (box % val_max < val_max - 2 && answer[0][box] == val_max && box % val_max != 0)
	{
		if (!four_is_placable(answer, box, val_max, "right"))
		{
			box = (box - (box % val_max)) + (val_max - 1);
			answer[0][box] = val_max - 1;
			remove_invalid_values(answer, val_max, box);
			(*changes)++;
		}
		else
		{
			away = (val_max - 2 - box % val_max);//l'ecart de cases
			while (i <= away)
				answer[i++][(box / val_max * val_max) + val_max - 1] = 0;
		}
	}
}

/* si j'ai un 1 devant une condition ou je dois afficher 2 tours je met ma val max */
void	two_in_cond(int **answer, int val_max, int box, int *changes, int *conditions)
{
	if (up_line_conds(box, val_max, conditions) == 2)
		two_in_cond_up(answer, val_max, box, changes);
	else if (low_line_conds(box, val_max, conditions) == 2)
		two_in_cond_low(answer, val_max, box, changes);
	else if(left_col_conds(box, val_max, conditions) == 2)
		two_in_cond_left(answer, val_max, box, changes);
	else if (right_col_conds(box, val_max, conditions) == 2)
		two_in_cond_right(answer, val_max, box, changes);
}

int ft_count_digits(int **answer, int val_max, int box)
{
	int i;
	int count_digits;

	count_digits = 0;
	i = 0;
	if (right_border(box, val_max))
	{
		while (i++ != val_max)
		{
			if (answer[0][box--] != 0)
				count_digits++;
		}
	}
	else
	{
		while (i++ != val_max)
		{
			if (answer[0][box] != 0)
				count_digits++;
			box -= val_max;
		}
	}
	return (count_digits);
}

void	last_digit(int **answer, int val_max, int box, int *changes)
{
	int count_digits;
	int i;

	i = 1;
	count_digits = ft_count_digits(answer, val_max, box);
	if (count_digits == val_max - 1)
	{
		if (right_border(box, val_max) && box > 0)
		{
			while (answer[0][box] != 0)
				box--;
		}
		else if (low_border(box, val_max) && box - val_max >= 0)
		{
			while (answer[0][box] != 0)
				box -= val_max;
		}
		while (i <= val_max)
		{
			if (answer[i][box] != 0)
			{
				answer[0][box] = answer[i][box];
				(*changes)++;
				remove_invalid_values(answer, val_max, box);
			}
			i++;
		}
	}
}

