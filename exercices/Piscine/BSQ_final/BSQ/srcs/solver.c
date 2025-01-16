/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/25 18:46:02 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_init_lol(t_coords *save)
{
	save[1].size = 1;
	save[0].col = save[0].col_backup;
	save[0].line_backup = save[0].line;
	save[1].col_backup = save[0].col_backup;
	save[1].line_backup = save[0].line_backup;
}

int	solver_part3(int count, t_coords *save)
{
	if (count > save[1].size)
	{
		save[1].size = count;
		save[1].col_backup = save[0].col_backup;
		save[1].line_backup = save[0].line_backup;
	}
	save[0].col++;
	count = 1;
	return (count);
}

int	solver_part2(char **map, t_coords *save, int k, int count)
{
	while (map[save[0].line + count] && map[save[0].line][save[0].col
		+ count] != '\0' && map[save[0].line
		+ count][save[0].col] == save[0].empty && map[save[0].line][save[0].col
		+ count] == save[0].empty && map[save[0].line + count][save[0].col
		+ count] == save[0].empty)
	{
		while (k < count && map[save[0].line + count][save[0].col
			+ k] == save[0].empty && map[save[0].line + k][save[0].col
			+ count] == save[0].empty && (map[save[0].line + count][save[0].col]
				|| map[save[0].line][save[0].col + count] != '\0'))
			k++;
		if (k == count)
		{
			count++;
			k = 1;
		}
		else
			break ;
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
	while (save[0].col < save[0].backup_obst)
	{
		if (map[save[0].line + count] && map[save[0].line][save[0].col
			+ count] != '\0' && map[save[0].line][save[0].col] == save[0].empty
			&& map[save[0].line + count][save[0].col] == save[0].empty
			&& map[save[0].line][save[0].col + count] == save[0].empty
			&& map[save[0].line + count][save[0].col + count] == save[0].empty)
		{
			save[0].col_backup = save[0].col;
			count = solver_part2(map, save, k, count);
		}
		count = solver_part3(count, save);
	}
}

char	**the_square(int *coords, char **tab, t_coords *res)
{
	int	x;
	int	y;
	int	size;
	int	bckpy;
	int	bckpx;

	y = coords[0];
	x = coords[1];
	size = coords[2];
	bckpy = y;
	bckpx = x;
	while (x < size + bckpx)
	{
		while (y < size + bckpy)
		{
			tab[x][y] = res[0].full;
			y++;
		}
		y = bckpy;
		x++;
	}
	return (tab);
}
