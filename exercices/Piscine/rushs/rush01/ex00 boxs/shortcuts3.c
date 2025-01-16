/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:32:19 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 09:32:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int	find_last_digit(int value, int **answer, int val_max)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < val_max * val_max)
	{
		if (answer[value][i] == value)
			count++;
		i++;
	}
	if (count == val_max)
	{
		i = -1;
		while (++i < val_max * val_max)
		{
			while (answer[value][i] == 0)
				i++;
			if ((answer[0][i] - answer[value][i]) != 0)
			{
				answer[0][i] = value;
			}
		}
	}
	return (count);
}

void	remove_invalid_values(int **answer, int val_max, int box)
{
	int	start;
	int	saved_value;

	start = box;
	saved_value = answer[0][box];                           
		// je prends la valeur que je viens de mettre en sauvegarde
	while (same_line(box, val_max, start - 1) && start >= 0)
		// je vais au debut de la ligne
		start--;
	while (same_line(box, val_max, start))
	{
		answer[saved_value][start] = 0;
			// j'enleve cette valeur des autres box de la ligne
		if (start == box)
			answer[saved_value][start] = saved_value;
		start++;
	}
	start = box;
	while ((start - val_max) >= 0) // je vais au debut de la colonne
		start -= val_max;
	while (start < val_max * val_max)
	{
		answer[saved_value][start] = 0;
			// j'enleve cette valeur des autres box de la colonne
		if (start == box)
			answer[saved_value][start] = saved_value;
		start += val_max;
	}
	find_last_digit(saved_value, answer, val_max);
}

void	one_to_5_in_col(int **answer, int val_max, int box, char *da_wae)
{
	int	one_to_5;

	if (!ft_strcmp(da_wae, "down")) // si j'ai val_max en condition du bas,
		j'ecris val_max...321 sur ma colonne
	{
		one_to_5 = val_max;
		while (box < val_max * val_max && one_to_5 >= 1)
		{
			answer[0][box] = one_to_5--;
			remove_invalid_values(answer, val_max, box);
			box += val_max;
		}
	}
	else if (!ft_strcmp(da_wae, "up"))
		// sinon j'ecris 123...val_max sur ma colonne
	{
		one_to_5 = 1;
		while (box < val_max * val_max && one_to_5 <= val_max)
		{
			answer[0][box] = one_to_5++;
			remove_invalid_values(answer, val_max, box);
			box += val_max;
		}
	}
}

void	one_to_5_in_line(int **answer, int val_max, int box, char *da_wae)
{
	int	one_to_5;
	int	col;

	col = box;
	if (!ft_strcmp(da_wae, "right")) // si j'ai val_max en condition de droite,
		j'ecris val_max...321 sur ma ligne
	{
		one_to_5 = val_max;
		while (same_line(box, val_max, col) && one_to_5 >= 1)
		{
			answer[0][box] = one_to_5--;
			remove_invalid_values(answer, val_max, box);
			box++;
		}
	}
	else if (!ft_strcmp(da_wae, "left"))
	{
		one_to_5 = 1;
		while (same_line(box, val_max, col) && one_to_5 <= val_max)
		{
			answer[0][box] = one_to_5++;
			remove_invalid_values(answer, val_max, box);
			box++;
		}
	}
}
