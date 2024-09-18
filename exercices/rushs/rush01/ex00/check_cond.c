/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:35:42 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/15 23:45:10 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_reverse_col_validity(int *answer, int cases, int val_max);
int check_reverse_line_validity(int *answer, int cases);
int check_col_validity(int *answer, int cases, int val_max);
int check_line_validity(int *answer, int cases, int val_max);

int check_lines_and_cols(int *conditions, int *answer, int cases, int val_max)//valide les valeurs de la ligne 1
{
	int	line;
	int	col;
	
	line = check_line_validity(answer, cases, val_max);
	col = check_col_validity(answer, cases, val_max);
	/*si le nombre que l'essaie de valider ne permet pas d'afficher suffisamment de tours*/
	if ((line > conditions[val_max * 2 + (cases / val_max)])
		|| answer[cases] >= (val_max - conditions[val_max * 0 + (cases % val_max)] + 2)
		|| ((line == conditions[val_max * 2 + (cases / val_max)]) && answer[cases] != val_max))//je verifie si j'affiche le bon nombre de tours en ligne
		return (0);//invalide
	if (cases % val_max == val_max - 1)//si je suis a la derniere colonne
	{
		line = check_reverse_line_validity(answer, cases);
		if (line != conditions[val_max * 3 + (cases / val_max)])//si mon nombre de tours ne correspond pas aux conditions de droite
			return (0);//invalide
	}
	if (col > conditions[val_max * 0 + (cases % val_max)]//si j'ai depasse le nombre de tours a afficher
		|| answer[cases] >= (val_max - conditions[val_max * 0 + (cases % val_max)] + 2)
		|| ((col == conditions[val_max * 0 + (cases % val_max)]) && answer[cases] != val_max))//ou si j'ai atteint le nombre avant 9
		return (0);//invalide
	if (cases / val_max == val_max - 1)//si je suis a la derniere ligne
	{
		col = check_reverse_col_validity(answer, cases, val_max);
		if (col != conditions[val_max * 1 + (cases / val_max)])//si mon nombre de tours ne correspond pas aux conditions de bas de ligne
			return (0);//invalide
	}
	return (1);
}

int check_same(int *answer, int cases, int val_max)//on verifie si on a un doublon
{
	int compare;
	
	compare = cases - 1;
	if (!cases % val_max == 0)//si je ne suis pas au debut de la ligne
	{
		while ((compare / val_max) == (cases / val_max))//tant qu'on est pas a la fin de la ligne
		{
			if (answer[compare] == answer[cases])//si j'ai un doublon
				return(0);
			compare--;
		}
	}
	compare = cases - val_max;
	if (!cases / val_max == 0)//si je ne suis pas au debut de la colonne
	{
		while (compare >= 0)//tant qu'on est pas a la fin de la colonne
		{
			if (answer[compare] == answer[cases])//si j'ai un doublon
				return(0);
			compare -= val_max;
		}
	}
	return (1);//pas de doublons
}


int check_dupl_cond(int *conditions, int *answer, int cases, int val_max)//verifie si les tours sont valides et si je n'ai pas de doublons
{
	int compteur_ligne;
	int compteur_colonne;
	
	if (!check_same(answer, cases, val_max))//on verifie si on a un doublon
		return (0);
	compteur_ligne = check_line_validity(answer, cases, val_max);//on compte le nombre de tours qu'on affiche sur la ligne
	compteur_colonne = check_col_validity(answer, cases, val_max);//on compte le nombre de tours qu'on affiche sur la colonne
	if (answer[cases] < val_max)//si ma valeur actuelle n'est pas ma valeur max
	{
		if (!(conditions[val_max * 2  + (cases % val_max)] > compteur_ligne - 1))//on regarde si les tours affichables sont coherentes avec la condition de gauche 
			return(0);//si pas coherent, return 0
		if (!(conditions[val_max * 0  + (cases % val_max)] > compteur_colonne - 1))//on regarde si les tours affichables sont coherentes avec la condition du haut 
			return(0);//si pas coherent, return 0
	}
	else//si ma valeur actuelle est ma valeur max
	{
		if (compteur_ligne != 1)//si c'est pas coherent sur la ligne
			return(0);
		if (compteur_colonne != 1)//si c'est pas coherent sur la colonne
			return(0);
	}
	return (1);//c'est coherent
}

int check_borders(int *conditions, int cases, int val_max)//verifie si je peux ecrire un 9
{
	if (cases / val_max == 0)//si je suis sur la bordure du haut et que j'ai un 1 en conditions
	{
		if (conditions[val_max * 0 + (cases % val_max)] == 1)
			return (1);// c'est bon, sinon on continu
	}
	if (cases / val_max == val_max - 1)//si je suis sur la bordure du bas et que j'ai un 1 en conditions
	{
		if (conditions[val_max * 1 + (cases % val_max)] == 1)
			return (1);// c'est bon, sinon on continu
	}
	if (cases % val_max == 0)//si je suis sur la bordure du haut et que j'ai un 1 en conditions
	{
		if (conditions[val_max * 2 + (cases % val_max)] == 1)
			return (1);// c'est bon, sinon on continu
	}
	if (cases % val_max == val_max -1)//si je suis sur la bordure du haut et que j'ai un 1 en conditions
	{
		if (conditions[val_max * 3 + (cases % val_max)] == 1)
			return (1);// c'est bon, sinon on continu
	}
	return (0);
}


int start_check(int *conditions, int *answer, int cases, int val_max)//fonction de depart
{
	if (((cases / val_max == 0) || (cases / val_max == val_max - 1)//si je suis sur une bordure avec un 9
		|| (cases % val_max == 0) || (cases % val_max == val_max -1))
		&& answer[cases] == val_max)
		{
			if (check_borders(conditions, cases, val_max))//si 9 est valide
				return (1);//c'est bon
		}
	if (!check_dupl_cond(conditions, answer, cases, val_max))//si j'ai pas de doublon
		return (0);//c'est bon
	if(check_lines_and_cols(conditions, answer, cases, val_max))//si mon nombre entre dans les conditions
		return (1);//c'est bon
	return (0);//c'est pas valide
}