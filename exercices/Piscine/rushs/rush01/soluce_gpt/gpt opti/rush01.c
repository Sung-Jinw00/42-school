/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursivity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:36:53 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 16:36:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

void	ft_write_cond(int *conds, char **av, int val_max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[1][i] && j < val_max * 4)//je convertis les chars en int en skippant les white spaces
	{
		conds[j] = av[1][i] - 48;
		j++;
		i += 2;
	}
}

void	ft_putstr(int **answer, int val_max, int * cond)
{
	int	i;

	i = 0;
	verif_conds(answer, val_max, cond);
	write_conds(cond, 1, 0, val_max);
	while (i < (val_max * val_max))
	{
		if (i % val_max == 0)
			write_conds(cond, 3, i, val_max);
		answer[0][i] += 48;
		write(1, &answer[0][i], 1);
		if ((i + 1) % val_max == 0)
		{
			write_conds(cond, 4, i, val_max);
			write(1, "\n", 1);
		}
		else
			 write(1, " ", 1);
		i++;
	}
	write_conds(cond, 2, 0, val_max);

}
void	ft_remove_if_digit(int **answer, int val_max)
{
	int val;
	int box;
	int i;

	i = 1;
	val = 0;
	box = 0;
	while (box < val_max * val_max)
	{
		if (answer[0][box] != 0)
		{
			val = answer[0][box];
			while (i <= val_max)
			{
				if (i != val)
					answer[i][box] = 0;
				i++;
			}
			i = 1;
		}
		box++;
	}
}

int ft_valid_conds(int **answer, int box)
{
	if (box == 2 && answer[0][0] == 5
		&& answer[0][1] == 6
		/* && answer[0][2] == 2
		&& answer[0][3] == 3
		&& answer[0][4] == 7
		&& answer[0][5] == 9
		&& answer[0][6] == 8
		&& answer[0][7] == 4
		&& answer[0][8] == 1 */)
		return(1);
	return(0);
}

void bp(void)
{
	return ;
}
int	ft_recursive_verif(int **answer, int box, int val_max, int *conds)
{
	int	i;
	int result;
	int **answer_copy;

	answer_copy = NULL;
	i = val_max;
	result = 0;
	if (answer[0][box] != 0)
	{
		if (box == (val_max * val_max - 1))
		{
			ft_putstr(answer, val_max, conds);//j'ecris la reponse
				result++;
		}
		else if (start_check(conds, answer, box, val_max))
		{
			mini_pre_filling(conds, answer, val_max, box);
			result += ft_recursive_verif(answer, box + 1, val_max, conds);
		}
	}
	else
	{
		answer_copy = ft_strdup(answer, val_max);
		while (box < (val_max * val_max) && i > 0)//tant que j'ai pas atteint mon nombre de box max
		{
			while (answer[i][box] == 0 && i > 0)
			{
				if (ft_valid_conds(answer, box) && i == 2)
					bp();
				i--;
			}
			if (ft_valid_conds(answer, box) && i == 2)
					bp();
			answer[0][box] = i--;//j'assigne ma valeur
			if (start_check(conds, answer, box, val_max) && answer[0][box] != 0)//et je commence le check
			{//si c'est bon
				if (box == (val_max * val_max - 1))//si j'arrive a la derniere case validee
				{
					ft_putstr(answer, val_max, conds);//j'ecris la reponse
					result++;
				}
				else
				{
					mini_pre_filling(conds, answer, val_max, box);
					result += ft_recursive_verif(answer, box + 1, val_max, conds);//je vais a la prochaine case
					free (answer);
					answer = ft_strdup(answer_copy, val_max);
				}
			}
			if (result == 1)
				break;
			answer[0][box] = 0;
		}
	}
	return (result);
}

void init_answer(int **answer, int val_max, int *conds)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= val_max)
	{
		while (j < val_max * val_max)
		{
			if (i == val_max - 1 && ((j / val_max == 1 && up_line_conds(j, val_max, conds) == 2)
			|| (j % val_max == 1 && left_col_conds(j, val_max, conds) == 2)
			|| (j % val_max == val_max - 2 && right_col_conds(j, val_max, conds) == 2)
			|| (j / val_max == val_max - 2 && low_line_conds(j, val_max, conds) == 2)))
				answer[i][j++] = 0;
			else
				answer[i][j++] = i;
		}
		i++;
		j = 0;
	}
	pre_filling(conds, answer, val_max);
}

void	limits(int **answer, int *conds, int val_max)
{
	int box;
	int vmax;

	box = 0;
	vmax = 0;
	while (box < val_max * val_max)//tant que je n'ai pas parcourru toutes mes cases
	{
		while (answer[0][box] != 0 && box < val_max * val_max)//tant que ma case n'est pas vide
		{
			remove_invalid_values(answer, val_max, box);//j'enleve les mauvaises valeurs
			box++;
		}
		if (box < val_max * val_max)//sinon le prends ma limite
			vmax = cross_opti(conds, box, val_max) + 1;
		while (vmax <= val_max)//et j'enleve tout ce qui est au dessus des possibilites
		{
			answer[vmax][box] = 0;
			vmax++;
		}
		box++;
	}
	box = 0;
	while (box <= val_max)
		find_last_digit(box++, answer, val_max);
	ft_remove_if_digit(answer, val_max);
}

int	rush01(char **av, int val_max)
{
	int	**answer;
	int	*conds;
	int	i;

	i = 0;
	conds = malloc(sizeof(int) * (val_max * 4));//j'alloue ma grille de conds
	answer = malloc(sizeof(int *) * (val_max + 1));
	while (i <= val_max)
		answer[i++] = malloc(sizeof(int) * (val_max * val_max));
	if (!conds || !answer)
		return (0);
	ft_write_cond(conds, av, val_max);//j'assigne ma grille de conds
	init_answer(answer, val_max, conds);//j'alloue et je remplis mes grille de reponses
	boss_killer(answer, /* conds, */ val_max);
	if (cond_peers_validity(conds, val_max))
		i = ft_recursive_verif(answer, 0, val_max, conds);//je verifie les valeurs
	else
		error_peers();
	if (i == 0)//si j'ai pas trouve de reponses correctes, erreur
		write(2, "aucune solution trouvee\n", 24);
	free (answer);
	free(conds);//je free mes mallocs
	return (0);
}
