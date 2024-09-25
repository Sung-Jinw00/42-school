/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:30:32 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/24 21:35:33 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

/* on gagne des lignes */
int	find_first_y(char **map, t_coords *save)
{
	save[0].line_backup = save[0].line;
	save[0].backup_obst = save[0].col;
	save[0].col = save[0].col_backup;
	save[0].line += 1;
	while (map[save[0].line][save[0].col])//tant que je suis pas arrive a la fin du tableau
	{
		if (save[0].col == save[0].backup_obst)//si j'arrive a la ligne ou j'ai croise mon 1er obstacle
		{
			save[0].line++;//je passe a la ligne suivante
			save[0].col = save[0].col_backup;//je regarde si j'ai des obstacles depuis le debut
		}
		if (map[save[0].line][save[0].col] == save[0].obstacle
			|| !map[save[0].line])//si je trouve un obstacle j'arrete ma boucle, j'ai mon x et y
			break;
		save[0].col++;
	}
	save[0].line = save[0].line_backup;
	return (1);
}
/* je trouve le premier carre */
void	find_first_square(int *coords, char **map, t_coords *save)
{
	save[0].line = 0;
	save[0].col = ft_skip_obst(map, save);//je skip si j'ai des obstacles au debut
	save[0].col_backup = save[0].col;//je marque mon debut de ligne sans obstacles
	while (map[save[0].line]
		&& (map[save[0].line][save[0].col] != save[0].obstacle
		&& map[save[0].line][save[0].col] != '\0'))//tant que mon tableau existe ou que j'ai pas d'obstacles
		save[0].col++;
	save[0].backup_obst = save[0].col;//je marque mon debut de ligne sans obstacles
	save[0].col = save[0].col_backup;//je marque mon debut de ligne sans obstacles
	solver(map, save);
	assign_new_coords(coords, save);
}
