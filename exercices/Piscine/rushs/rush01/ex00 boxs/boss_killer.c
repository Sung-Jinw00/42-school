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
	cpy = malloc(sizeof(int *) * (val_max + 1));
	if (!cpy)
		return (NULL);
	while (i <= val_max)
	{
		cpy[i] = malloc(sizeof(int) * (val_max * val_max));
		if (!cpy[i]) // Vérifiez l'allocation
        {
            while (i > 0)
                free(cpy[--i]); // Libération de la mémoire déjà allouée
            free(cpy);
            return (NULL);
        }
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