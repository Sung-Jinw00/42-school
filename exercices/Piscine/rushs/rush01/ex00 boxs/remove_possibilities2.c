/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_possibilities2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:03:28 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 20:03:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

/* enleves toutes les possibilites dans i et j */
void shorten_possibilities_col(int **answer, int val_max, int box, int vals_to_keep, int *changes)
{
	int start_col;
	int end_col;
	int k;
	int cmp;

	k = 1;
	cmp = 0;
	start_col = box % val_max;//je vais au debut de la colonne
	end_col = start_col + val_max * val_max;//je marque la fin de ma colonne
	while (start_col < end_col)//tant que je suis pas arriver a la fin de ma colonne
	{
		if (start_col > vals_to_keep)//si mon increment depasse ma premiere case a garder
		{
			cmp = vals_to_keep + val_max;
			while (!comp_possibilities(answer, val_max, vals_to_keep, cmp) && cmp < end_col)
				cmp += val_max;
			if (cmp < end_col)
				vals_to_keep = cmp;//je vais a la suivante
		}
		while (k <= val_max)//tant que j'ai pas check le dernier tableau de valeurs
		{
			if (answer[k][start_col] != 0//si la valeur n'est pas zero
				&& answer[k][start_col] == answer[k][vals_to_keep] //et que ma valeur est egal a une de celles que je dois garder
				&& start_col != vals_to_keep)//et que je suis pas sur une case ou je dois garder mes valeurs
			{
				answer[k][start_col] = 0;//je met a zero
				(*changes)++;
			}
			k++;
		}
		if (one_possibility_left(answer, start_col, val_max))//si y me reste un nombre dans la case, je le met et j'enleve les possibilites supperflues
			(*changes)++;
		k = 1;
		start_col += val_max;
	}
}
/* comme je sais combien de tours je peux afficher dans chaque case, il faut juste que je regarde si
j'ai les memes tours dans les cases correspondantes,
j'ajoute + 1 au compteur si c'est bon, si mon compteur est egal au nombre de tours que je peux afficher, j'enleve tous les autres
nombres tant que je suis pas aux endroits qui correspondent aux numeros de mon compteur*/
int compare_same_nbs_col(int **answer, int val_max, int box, int *changes)
{
	int compteur;
	int start_col;
	int cmp;
	int stop_col;

	compteur = 1;
	start_col = box % val_max;//je vais au debut de la colonne
	cmp = start_col + val_max;
	stop_col = start_col + val_max * val_max;//je marque la fin de ma colonne
	while (start_col < stop_col)//tant que je suis pas arriver a la fin de ma colonne
	{
		while (cmp < stop_col)//tant que je suis pas arriver a la fin de ma colonne
		{
			if (answer[val_max + 2][start_col] == answer[val_max + 2][cmp])
				if (comp_possibilities(answer, val_max, start_col, cmp))//si j'ai le meme nombre de tours affichables
					compteur++;//j'ai un doublon
			if (compteur == answer[val_max + 2][start_col])//si j'ai suffisament de cases pour afficher toutes les potentielles tours
			{
				shorten_possibilities_col(answer, val_max, box, compteur, changes);//j'enleve les tours des autres cases
				break;//je vais a la prochaine case
			}
			cmp += val_max;
		}
		start_col += val_max;
		cmp = start_col + val_max;
		compteur = 1;
	}
	return (0);
}

void if_same_vals_col(int **answer, int val_max, int box, int *changes)
{
	/* deja je regade combien de chiffres je peux mettre dans chaque case */
	int start_col;
	int stop_col;
	int k;
	int nb;

	k = val_max;
	answer[val_max + 2] = malloc(sizeof(int) * val_max);//je malloc un tableau pour une colonne
	start_col = box % val_max;//je vais au debut de la colonne
	stop_col = start_col + val_max * val_max;//je marque la fin de ma colonne
	while (start_col < stop_col)//tant que je suis pas arriver a la fin de ma colonne
	{
		while (k > 0)//tant que j'ai pas regarder toutes les valeurs disponibles
		{
			if (answer[k--][start_col] != 0)//si j'ai une valeur affichable theoriquement
				nb++;
		}
		answer[val_max + 2][start_col % val_max] = nb;//je met le nombre de valeurs affichables dans la case de ma colonne correspondante
		start_col += val_max;
		k = val_max;
	}
	/* ensuite je compare le nombre de valeurs que j'ai trouver */
	compare_same_nbs_col(answer, val_max, box, changes);
	free(answer[val_max + 2]);
}
