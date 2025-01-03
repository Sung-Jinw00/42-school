/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:53:56 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/03 17:56:58 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	error(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

char	*set_args(char *arg, int arg_nb)
{
	int i;

	if (!arg)
		error(RED"No name specified !\n"RESET);
	i = 0;
	if (arg[i] >= 'a' && arg[i] <= 'z')
		arg[i] -= 32;
	while (arg[++i])
		if (arg[i] >= 'A' && arg[i] <= 'Z')
			arg[i] += 32;
	if (!ft_strcmp(arg, MANDELBROT) && arg_nb == 1)
		return (MANDELBROT);
	else if (!ft_strcmp(arg, JULIA) && arg_nb == 1)
		return (JULIA);
	else if (arg_nb == 1)
		return (error(RED"Invalid name, please try again !\n"RESET), NULL);
	if (!ft_strcmp(arg, PRESET) && arg_nb == 2)
		return (PRESET);
	else
		return (NULL);
}
