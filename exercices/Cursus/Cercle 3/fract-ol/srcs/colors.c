/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:29:59 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/15 16:52:33 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static double	my_sin(double x)
{
	double	result;
	double	term;
	int		i;

	result = 0.0;
	term = x;
	i = 1;
	result += term;
	while (i <= 5)
	{
		term *= -x * x / ((2 * i) * (2 * i + 1));
		result += term;
		i++;
	}
	return (result);
}

static double	my_cos(double x)
{
	double	result;
	double	term;
	int		i;

	result = 1.0;
	term = 1.0;
	i = 1;
	while (i <= 5)
	{
		term *= -x * x / ((2 * i - 1) * (2 * i));
		result += term;
		i++;
	}
	return (result);
}

unsigned int	rotate_hue(double iter)
{
	t_colors	colors;

	colors.alpha = 0;
	colors.coef = 510.0 / MAX_ITER;
	colors.color = iter * colors.coef;
	if (colors.color > 510.0)
	{
		colors.color = 510.0;
	}
	colors.angle = colors.color / 255.0 * PI / 2;
	colors.red = (unsigned int)(255 * (1 - my_cos(colors.angle)));
	colors.green = (unsigned int)(255 * (1 - my_cos(colors.angle)));
	colors.blue = (unsigned int)(255 * my_sin(colors.angle));
	return ((colors.alpha << 24) | (colors.red << 16) | (colors.green << 8) | colors.blue);
}
