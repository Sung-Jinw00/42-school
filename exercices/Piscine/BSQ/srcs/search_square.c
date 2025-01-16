/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:38:46 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/25 16:37:35 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	*find_another_square(int *coords, char **map, t_coords *save)
{
	while (map[save[0].line] && map[save[0].line][save[0].col])
	{
		if (map[save[0].line][save[0].col] == save[0].obstacle)
			save[0].col = ft_skip_obst(map, save);
		if (map[save[0].line][save[0].col] == save[0].empty)
			save[0].col_backup = save[0].col;
		while (map[save[0].line][save[0].col] != save[0].obstacle
			&& map[save[0].line][save[0].col] != '\0')
			save[0].col++;
		save[0].backup_obst = save[0].col;
		save[0].col = save[0].col_backup;
		solver(map, save);
		if (coords[2] < save[1].size)
			assign_new_coords(coords, save);
		if (map[save[0].line][save[0].col] == '\0'
			|| map[save[0].line][save[0].col + 1] == '\0')
		{
			save[0].col = -1;
			save[0].backup_obst = 0;
			save[0].col_backup = 0;
			save[0].line += 1;
		}
		save[0].col++;
	}
	return (coords);
}

int	*search_square(char **tab, char *buffer, t_coords *save)
{
	int	*coords;
	int	i;

	i = 0;
	coords = (int *)malloc(sizeof(int) * 3);
	save[0].empty = buffer[0];
	save[0].obstacle = buffer[1];
	save[0].full = buffer[2];
	save[0].col = 0;
	save[0].line = 0;
	find_first_square(coords, tab, save);
	coords = find_another_square(coords, tab, save);
	return (coords);
}
