/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:30:32 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 18:43:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	find_first_y(char **map, t_coords *save)
{
	save[0].line_backup = save[0].line;
	save[0].backup_obst = save[0].col;
	save[0].col = save[0].col_backup;
	save[0].line += 1;
	while (map[save[0].line][save[0].col])
	{
		if (save[0].col == save[0].backup_obst)
		{
			save[0].line++;
			save[0].col = save[0].col_backup;
		}
		if (map[save[0].line][save[0].col] == save[0].obstacle
			|| !map[save[0].line])
			break ;
		save[0].col++;
	}
	save[0].line = save[0].line_backup;
	return (1);
}

void	find_first_square(int *coords, char **map, t_coords *save)
{
	save[0].line = 0;
	save[0].col = ft_skip_obst(map, save);
	save[0].col_backup = save[0].col;
	while (map[save[0].line]
		&& (map[save[0].line][save[0].col] != save[0].obstacle
		&& map[save[0].line][save[0].col] != '\0'))
		save[0].col++;
	save[0].backup_obst = save[0].col;
	save[0].col = save[0].col_backup;
	solver(map, save);
	if (map[save[0].line][save[0].col] == '\0' || map[save[0].line][save[0].col
		+ 1] == '\0')
	{
		save[0].col = 0;
		save[0].backup_obst = 0;
		save[0].col_backup = 0;
		save[0].line += 1;
	}
	assign_new_coords(coords, save);
}
