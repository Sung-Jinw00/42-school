/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_killer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:02:34 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 22:02:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int		**ft_strdup(int **src, int val_max)
{
	int		**cpy;
	int		i;
	int		j;

	i = 0;
	j = -1;
	cpy = (int **)malloc(sizeof(int *) * val_max + 1);
	if (!cpy)
		return (NULL);
	while (i <= val_max)
	{
		cpy[i] = (int *)malloc(sizeof(int) * val_max * val_max);
		while (++j < val_max * val_max)
			cpy[i][j] = src[i][j];
		i++;
		j = -1;
	}
	return (cpy);
}

/* int	test_values(int **answer, int box, int val_max, int *conds)
{
	int **answer_copy;
	answer_copy = ft_strdup(answer, val_max);

	free(answer_copy); 
} */

void	boss_killer(int **answer, /* int *conditions, */ int val_max)
{
	int changes;
	int box;

	changes = 1;
	box = 0;
	while (changes != 0)
	{
		changes = 0;
		while (box < val_max * val_max)
		{
			if_same_vals_line(answer, val_max, box, &changes);
			if_same_vals_col(answer, val_max, box, &changes);
			one_number_left(answer, box, val_max);
			/* if (!up_border(box, val_max) || !low_border(box, val_max)
				|| !right_border(box, val_max) || !left_border(box, val_max))
				test_values(answer, box, val_max, conditions); */
			box += val_max + 1;
		}
		box = 0;
	}
}