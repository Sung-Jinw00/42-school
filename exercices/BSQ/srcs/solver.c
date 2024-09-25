/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/24 21:11:47 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lib.h"

void	ft_init_lol(t_coords *save)
{
	save[1].size = 1;
	save[0].col = save[0].col_backup;
	save[0].line_backup = save[0].line;
}

int	solver_part2(char **map, t_coords *save, int k, int count)
{
	while (map[save[0].line + count] 
		&& map[save[0].line][save[0].col + count] != '\0'
		&& map[save[0].line + count][save[0].col] == save[0].empty
		&& map[save[0].line][save[0].col + count] == save[0].empty
		&& map[save[0].line + count][save[0].col + count] == save[0].empty)//tant que les bords du nouveau carre sont corrects
	{
		while (k < count && map[save[0].line + count][save[0].col + k] == save[0].empty
		&& map[save[0].line + k][save[0].col + count] == save[0].empty
		&& (map[save[0].line + count][save[0].col]
		|| map[save[0].line][save[0].col + count] != '\0'))//tant que j'ai des cases vides dans les bordures je check une longueur de plus (i)
			k++;//je vais jusqu'au coin inferieur droit du carree en checkant toutes les cases
		if (k == count)//si j'atteinds la fin du carre
		{
			count++;//je check une taille au dessus;
			k = 1;//je remet le check a la case d'a cote
		}
		else
			break;
	}
	return (count);
}

void	solver(char **map, t_coords *save)
{
	int	count;
	int	k;

	count = 1;
	k = 0;
	ft_init_lol(save);
	while (save[0].col < save[0].backup_obst)//tant que j'ai pas fini de scanner ma ligne
	{
		if (map[save[0].line + count]
			&& map[save[0].line][save[0].col + count] != '\0'
			&& map[save[0].line][save[0].col] == save[0].empty
			&& map[save[0].line + count][save[0].col] == save[0].empty
			&& map[save[0].line][save[0].col + count] == save[0].empty
			&& map[save[0].line + count][save[0].col + count] == save[0].empty)//si j'ai un debut de carre
		{
			save[0].col_backup = save[0].col;//je sauvegarde la coordonnee
			count = solver_part2(map, save, k, count);
		}
		if (count > save[1].size)//si j'ai une taille de carree plus grande que la precedente, je stock les infos dans le map 1
		{
			save[1].size = count;
			save[1].col_backup = save[0].col_backup;
			save[1].line_backup = save[0].line_backup;
		}
		save[0].col++;
		count = 1;
	}
}

char **the_square(int *coords, char **tab, t_coords *res)
{
	int x;
	int y;
	int size;
	int bckpy;
	int bckpx;
	
	y = coords[0];
	x = coords[1];
	size = coords[2];
	bckpy = y;
	bckpx = x;
	while (x < size + bckpx)
	{
		while(y < size + bckpy)
		{
			tab[x][y] = res[0].full;
			y++;
		}
		y = bckpy;
		x++;
	}
	return(tab);
}
