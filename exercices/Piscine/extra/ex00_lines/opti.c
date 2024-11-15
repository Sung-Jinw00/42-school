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

#include "lib.h"

int	*ft_strdup(int *src, int size)
{
	int	*cpy;
	int		len_src;
	int		i;

	i = 0;
	len_src = size + 1;
	cpy = (int *)malloc(sizeof(int) * len_src);
	if (!cpy)
		return (NULL);
	while (i < len_src)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

/* creer un tableau avec toutes les combinaisons possibles */
int **all_possibilities(int min, int max)
{
	int **possibilities;
	int cmb_nbs;
	int i = 0;
	int j = 0;
	int k = max - min + 1;
	int save_min = min;
	int *solution;

	cmb_nbs = ft_recursive_factorial(k);
	possibilities = malloc(sizeof(int *) * cmb_nbs);
	possibilities[i] = malloc(sizeof(int) * k);
	while (min <= max)
		possibilities[i][j++] = min++;
	min = save_min;
	while (++i < cmb_nbs)
	{
		k = max - min;//je pars de la fin du tableau
		solution = malloc(sizeof(int) * k);
		solution = ft_strdup(possibilities[i - 1], k);//je pars de mon tableau d'avant
		solution[k]++;//j'augmente de 1
		while (if_charset(solution[k], solution, k))//et je continu d'augmenter tant que ma valeur est egale a une valeur d'avant
			solution[k]++;
		while (solution[k] > max)//tant que ma valeur depasse 4 je remet ma valeur a 1 et j'ajoute + 1 a la valeur d'avant
		{
			solution[k--] = min;
			solution[k]++;
			while (if_charset(solution[k], solution, k))//et je continu d'augmenter tant que ma valeur est egale a une valeur d'avant
				solution[k]++;
		}
		k++;
		while (k - 1 < max - min)//tant que je suis pas revenu a la fin
		{
			while (if_charset(solution[k], solution, k))//tant que ma valeur correspond a une valeur precedente
				solution[k]++;//j'augmente
			k++;//puis je passe a la suivante
		}
		possibilities[i] = ft_strdup(solution, k + 1);//j'ai trouve une solution, je la sauvegarde et je passe a la suivante
		free(solution);
	}
	return (possibilities);
}

int	cross_opti(int *conditions, int box, int val_max)
{
	int box_limit;
	int pos_var;
	pos_var = ((box / val_max) + 1);//je dis a combien de box je suis de ma condition du haut
	if (pos_var >= conditions[up_line_conds(box, val_max)])//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = conditions[up_line_conds(box, val_max)];//je peux mettre ma val max
	box_limit = val_max - conditions[up_line_conds(box, val_max)] + pos_var;//j'ajuste ma val max en fonction de ma case

	pos_var = ((box % val_max) + 1);//je dis a combien de box je suis de ma condition de gauche
	if (pos_var >= conditions[left_col_conds(box, val_max)])//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = conditions[left_col_conds(box, val_max)];//je peux mettre ma val max
	if (box_limit > (val_max - conditions[left_col_conds(box, val_max)] + pos_var))//si ma val max d'avant est plus grande que la nouvelle
		box_limit = val_max - conditions[left_col_conds(box, val_max)] + pos_var;//j'ajuste ma val max en prenant la plus petite

	pos_var = val_max - (box % val_max);//je dis a combien de box je suis de ma condition de droite
	if (pos_var >= conditions[right_col_conds(box, val_max)])//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = conditions[right_col_conds(box, val_max)];//je peux mettre ma val max
	if (box_limit > (val_max - conditions[right_col_conds(box, val_max)] + pos_var))//si ma val max d'avant est plus grande que la nouvelle
		box_limit = val_max - conditions[right_col_conds(box, val_max)] + pos_var;//j'ajuste ma val max en prenant la plus petite

	pos_var = val_max - (box / val_max);//je dis a combien de box je suis de ma condition du bas
	if (pos_var >= conditions[low_line_conds(box, val_max)])//si j'ai au moins atteint le nombre de box minimum pour remplir ma condition
		pos_var = conditions[low_line_conds(box, val_max)];//je peux mettre ma val max
	if (box_limit > (val_max - conditions[low_line_conds(box, val_max)] + pos_var))//si ma val max d'avant est plus grande que la nouvelle
		box_limit = val_max - conditions[low_line_conds(box, val_max)] + pos_var;//j'ajuste ma val max en prenant la plus petite
	return (box_limit);//je rends la limite la plus petite
}

void bp(void)
{
	return ;
}

int *find_comb(datas *params, int *cmb_nb, int *reset, int line, int **answer)
{
	int box;
	int val_limit;
	int equiv_box;
	int cmb_nbr = *cmb_nb;
	int cur_val = 0;

	if (cmb_nbr == -1)//si j'arrive a la fin de mes combinaisons
		return (reset);//je renvoie aucune solution
	box = 0;//je donne le debut de la combinaison a box
	equiv_box = find_equiv_box(box, params->val_max, line);//je prend la case du tableau equivalente
	while ((equiv_box / params->val_max) == line)//tant que je suis sur la meme ligne
	{
			if (cmb_nbr < 1166 && cmb_nbr > 1000 && box == 1 && line == 0)
				bp();
		cur_val = params->combs[cmb_nbr][box];
		val_limit = cross_opti(params->conditions, equiv_box, params->val_max);//je prends ma val max avec mes params->conditions
		while (params->combs[cmb_nbr][box] > val_limit)//tant que je ma valeur est au dessus de ma limite
		{
			cmb_nbr--;//je decremente
			if (cmb_nbr == -1)//si j'arrive a la fin de mes combinaisons
				return (reset);//je renvoie aucune solution
			else if (cmp_dup_1col(answer, line, box, cur_val))
				{
					while (params->combs[cmb_nbr][box] == cur_val)
					{
						cmb_nbr--;
						if (cmb_nbr == -1)
							return (reset);
					}
				}
			else if (params->combs[cmb_nbr][box - 1] > \
			cross_opti(params->conditions, equiv_box - 1, params->val_max) && box - 1 >= 0)//sinon si ma valeur precedente deviens superieure a la valeur max precedente
			{
				box = 0;//je refais le check depuis le debut de ma condition actuelle
				equiv_box = find_equiv_box(box, params->val_max, line) - 1;
				box = -1;
				break;
			}
		}
		equiv_box++;
		box++;//je passe a la valeur d'apres
	}
	*cmb_nb = cmb_nbr;
	return (params->combs[cmb_nbr]);//je retourne la valeur trouvee
}
/* #include <stdio.h>
	if (line == 0 && box == 0 && cmb_nbr == 639)
		printf("limite de la case : %d\n", box_limit);
			if (line == 0 && cmb_nbr == 638)
				printf("combinaison testee : %d\n", cmb_nbr);
			if (line == 0 && cmb_nbr == 638)
				printf("limite case %d : %d\n\n", cmb_nbr, val_limit); */