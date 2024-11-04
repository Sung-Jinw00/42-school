/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_possibilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:01:45 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 20:01:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

int	comp_possibilities(int **answer, int val_max, int i, int j)
{
	int k;

	k = 0;
	while (k <= val_max)//je compare toutes les valeurs affichables des 2 cases
	{
		if (answer[k][i] != answer[k][j])//si c'est different je sors
			break;
		k++;
	}
	if (k - 1 == val_max)//si je suis arriver a val_max + 1, c'est que j'ai les memes valeurs
		return (1);
	return (0);
}

void one_nb_line(int **answer, int k, int box, int val_max)
{
	int start_line;
	int stop_line;
	int count;

	count = 0;
	start_line = (box / val_max) * val_max;//je vais au debut de la ligne
	stop_line = start_line + val_max;//je marque la fin de ma ligne
	while (start_line < stop_line)
	{
		if (answer[k][start_line] == k)
			count++;
		start_line++;
	}
	if (count == 1)
	{
		while (answer[k][start_line] != k || start_line == stop_line)
			start_line--;
		answer[0][start_line] = k;
		remove_invalid_values(answer, val_max, start_line);
	}
}
void one_nb_col(int **answer, int k, int box, int val_max)
{
	int start_col;
	int stop_col;
	int count;

	count = 0;
	start_col = box % val_max;//je vais au debut de la colonne
	stop_col = start_col + val_max * val_max;//je marque la fin de ma colonne
	while (start_col < stop_col)
	{
		if (answer[k][start_col] == k)
			count++;
		start_col += val_max;
	}
	if (count == 1)
	{
		while (answer[k][start_col] != k || start_col == stop_col)
			start_col -= val_max;
		answer[0][start_col] = k;
		remove_invalid_values(answer, val_max, start_col);
	}
}

void one_number_left(int **answer, int box, int val_max)
{
	int k;

	k = 1;
	while (k <= val_max)
	{
		one_nb_line(answer, k, box, val_max);
		one_nb_col(answer, k, box, val_max);
		k++;
	}
}

int one_possibility_left(int **answer, int box, int val_max)
{
	int k;
	int count;

	k = 1;
	count = 0;
	while (k <= val_max)//je compte le nombre de chiffres qu'il me reste
	{
		if (answer[k++][box] != 0)
			count++;
	}
	if (count == 1)//si il m'en reste qu'un
	{
		k--;
		while (answer[k][box] == 0)
			k--;
		if (answer[0][box] != answer[k][box])//si j'ai pas deja la valeur
		{
			answer[0][box] = answer[k][box];//je donne la valeur
			remove_invalid_values(answer, val_max, box);
			return (1);//j'ai modifie
		}
	}
	return (0);
}
/* enleves toutes les possibilites dans i et j */
void shorten_possibilities_line(int **answer, int val_max, int box, int vals_to_keep, int *changes)
{
	int start_line;
	int end_line;
	int k;
	int cmp;

	k = 1;
	cmp = 0;
	start_line = (box / val_max) * val_max;//je vais au debut de la ligne
	end_line = start_line + val_max;
	while (start_line < end_line)//tant que je suis pas arriver a la fin de ma ligne
	{
		if (start_line > vals_to_keep)
		{
			cmp = vals_to_keep + 1;
			while (!comp_possibilities(answer, val_max, vals_to_keep, cmp) && cmp < end_line)
				cmp++;
			if (cmp < end_line)
				vals_to_keep = cmp;
		}
		while (k <= val_max)//tant que j'ai pas check le dernier tableau de valeurs
		{
			if (answer[k][start_line] != 0//si la valeur n'est pas zero
				&& answer[k][start_line] == answer[k][vals_to_keep] //et que ma valeur est egal a une de celles que je dois garder
				&& start_line != vals_to_keep)//et que je suis pas sur une case ou je dois garder mes valeurs
			{
				answer[k][start_line] = 0;//je met a zero
				(*changes)++;
			}
			k++;
		}
		if (one_possibility_left(answer, start_line, val_max))
			(*changes)++;
		k = 1;
		start_line++;
	}
}
/* comme je sais combien de tours je peux afficher dans chaque case, il faut juste que je regarde si
j'ai les memes tours dans les cases correspondantes,
j'ajoute + 1 au compteur si c'est bon, si mon compteur est egal au nombre de tours que je peux afficher, j'enleve tous les autres
nombres tant que je suis pas aux endroits qui correspondent aux numeros de mon compteur*/
int compare_same_nbs_line(int **answer, int val_max, int box, int *changes)
{
	int compteur;
	int start_line;
	int cmp;
	int stop_line;

	compteur = 1;
	start_line = (box / val_max) * val_max;//je vais au debut de la ligne
	cmp = start_line + 1;
	stop_line = start_line + val_max;//je marque la fin de ma ligne
	while (start_line < stop_line)//tant que je suis pas arriver a la fin de ma ligne
	{
		while (cmp < stop_line)//tant que je suis pas arriver a la fin de ma ligne
		{
			if (answer[val_max + 1][start_line] == answer[val_max + 1][cmp])
				if (comp_possibilities(answer, val_max, start_line, cmp))//si j'ai le meme nombre de tours affichables
					compteur++;//j'ai un doublon
			if (compteur == answer[val_max + 1][start_line])//si j'ai suffisament de cases pour afficher toutes les potentielles tours
			{
				shorten_possibilities_line(answer, val_max, box, compteur, changes);//j'enleve les tours des autres cases
				break;//je vais a la prochaine case
			}
			cmp++;
		}
		start_line++;
		cmp = start_line + 1;
		compteur = 1;
	}
	return (0);
}

void if_same_vals_line(int **answer, int val_max, int box, int *changes)
{
	/* deja je regade combien de chiffres je peux mettre dans chaque case */
	int start_line;
	int stop_line;
	int k;
	int nb;

	k = val_max;
	answer[val_max + 1] = malloc(sizeof(int) * val_max);//je malloc un tableau pour une ligne
	start_line = (box / val_max) * val_max;//je vais au debut de la ligne
	stop_line = start_line + val_max;//je marque la fin de ma ligne
	while (start_line < stop_line)//tant que je suis pas arriver a la fin de ma ligne
	{
		while (k > 0)//tant que j'ai pas regarder toutes les valeurs disponibles
		{
			if (answer[k--][start_line] != 0)//si j'ai une valeur affichable theoriquement
				nb++;
		}
		answer[val_max + 1][start_line % val_max] = nb;//je met le nombre de valeurs affichables dans la case de ma ligne correspondante
		start_line++;
		k = val_max;
	}
	/* ensuite je compare le nombre de valeurs que j'ai trouver */
	compare_same_nbs_line(answer, val_max, box, changes);
	free(answer[val_max + 1]);
}
