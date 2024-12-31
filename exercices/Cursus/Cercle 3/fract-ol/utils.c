/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:53:56 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/31 20:13:10 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	error(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

char	*ft_fratal_name(char *fractal_name)
{
	int i;

	if (!fractal_name)
		error(RED"No name specified !\n"RESET);
	i = 0;
	if (fractal_name[i] >= 'a' && fractal_name[i] <= 'z')
		fractal_name[i++] -= 32;
	while (fractal_name[i])
		if (fractal_name[i] >= 'A' && fractal_name[i] <= 'Z')
			fractal_name[i++] += 32;
	if (fractal_name == MANDELBROT)
		return (MANDELBROT);
	else if (fractal_name == JULIA)
		return (JULIA);
	else
		error(RED"Invalid name, please try again !\n"RESET);
}
