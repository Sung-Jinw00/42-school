/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:33:42 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/25 23:30:40 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_skip_obst(char **map, t_coords *save)
{
	while (map[save[0].line][save[0].col] != '\0'
		&& map[save[0].line][save[0].col] == save[0].obstacle)
	{
		if (map[save[0].line][save[0].col + 1] == '\0')
		{
			save[0].line++;
			save[0].col = -1;
		}
		save[0].col++;
	}
	return (save[0].col);
}

char	*catch_param(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	buffer[i] = 0;
	i = 0;
	while (buffer[i] == '0')
		i++;
	while ((buffer[i] >= '0' && buffer[i] <= '9') && buffer[i + 3] != 0)
		i++;
	buffer = &buffer[i];
	i = ft_strlen(buffer);
	if (i == 3)
	{
		if (buffer[i - 1] != buffer[i - 2] && buffer[i - 1] != buffer[i - 3]
			&& buffer[i - 2] != buffer[i - 3])
			return (buffer);
	}
	return (0);
}

int	catch_param2(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] == '0')
		i++;
	while ((buffer[i] >= '0' && buffer[i] <= '9') && buffer[i + 3] != 0)
		i++;
	buffer[i] = 0;
	return (ft_atoi(buffer));
}

void	assign_new_coords(int *coords, t_coords *save)
{
	coords[0] = save[1].col_backup;
	coords[1] = save[1].line_backup;
	coords[2] = save[1].size;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
