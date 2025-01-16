/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cond2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:38:39 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/15 23:46:07 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_reverse_col_validity(char *answer, int cases, int val_max)
		// on regarde si les tours affichables sont coherentes avec la condition du haut
{
	int col;
	int compteur;

	col = cases - val_max;
	compteur = 1;
	if (answer[col] == '9')
	{
		compteur++;
		return (compteur);
	}
	while (answer[col] != '9') // tant que je suis pas arrive a 9
	{
		if (answer[cases] < answer[col])
			// si j'ai une tour plus grande que celle de la fin de la ligne
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			cases = col;
		}
		col -= val_max;
	}
	return (compteur); // je rends le compteur
}

int	check_reverse_line_validity(char *answer, int cases)
		// on regarde si les tours affichables sont coherentes avec la condition de gauche
{
	int line;
	int compteur;

	line = cases - 1;
	compteur = 1;
	if (answer[line] == '9')
	{
		compteur++;
		return (compteur);
	}
	while (answer[line] != '9') // tant que je suis pas arrive a 9
	{
		if (answer[cases] < answer[line])
			// si j'ai une tour plus grande que celle de la fin de la ligne
		{
			compteur++;
				// j'augmente le compteur du nombre de tours qu'on affiche
			cases = line;
		}
		line--;
	}
	return (compteur); // je rends le compteur
}

int	check_col_validity(char *answer, int cases, int val_max)
		// on regarde si les tours affichables sont coherentes avec la condition du haut
{
	int col;
	int j;
	int compteur;

	col = cases - val_max;
	compteur = 1;
	if (!(cases / val_max == 0)) // si je suis pas au debut de la colonne
	{
		while (col >= 0) // je decremente au debut de la colonne
			col -= val_max;
		col += val_max;
		j = col + 1;
		while (j <= cases) // tant que je suis pas revenu a ma cases
		{
			if (answer[col] < answer[j])
				// si j'ai une tour plus grande que celle du debut
			{
				compteur++;
					// j'augmente le compteur du nombre de tours qu'on affiche
				col = j;
			}
			j += val_max;
		}
	}
	return (compteur); // je rends le compteur
}

int	check_line_validity(char *answer, int cases, int val_max)
		// on regarde si les tours affichables sont coherentes avec la condition de gauche
{
	int line;
	int j;
	int compteur;

	line = cases - 1;

	compteur = 1;
	if (!(cases % val_max == 0)) // si je suis pas au debut de la ligne
	{
		while ((line / val_max) == (cases / val_max))
			// je decremente au debut de la ligne
			line--;
		line++;
		j = line + 1;
		while (j <= cases) // tant que je suis pas revenu a ma cases
		{
			if (answer[line] < answer[j])
				// si j'ai une tour plus grande que celle du debut
			{
				compteur++;
					// j'augmente le compteur du nombre de tours qu'on affiche
				line = j;
			}
			j++;
		}
	}
	return (compteur); // je rends le compteur
}