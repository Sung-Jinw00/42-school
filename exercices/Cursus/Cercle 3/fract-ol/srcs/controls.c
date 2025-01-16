/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:34:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/16 19:22:36 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	arrow_controls(int key, t_mlx *mlx)
{
	if (key == XK_Left)
		mlx->f_params.shift_x -= 0.01;
	else if (key == XK_Right)
		mlx->f_params.shift_x += 0.01;
	else if (key == XK_Up)
		mlx->f_params.shift_y -= 0.01;
	else if (key == XK_Down)
		mlx->f_params.shift_y += 0.01;
	else if (key == XK_r)
	{
		set_fractal_datas(mlx, mlx->ac, mlx->av);
		mlx->f_params.ratio = 2.5;
		mlx->f_params.shift_y = -(2.5 / 2);
		if (ft_strcmp_frctl(mlx->f_params.name, JULIA) == 0)
		{
			mlx->f_params.shift_x = -2.5 + 0.6;
		}
		else if (ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) == 0)
			mlx->f_params.shift_x = -2.5;
	}
	image_refresh(mlx);
}

void	mouse_controls2(int key, int x, int y, t_mlx *mlx)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (((double)x - WIDTH / 2) * mlx->pixel.x_value) / 9.5;
	mouse_y = (((double)y - HEIGHT / 2) * mlx->pixel.y_value) / 9.5;
	if (key == SCROLL_DOWN)
	{
		mlx->f_params.ratio *= 1.1;
		mlx->f_params.shift_x = ((mlx->f_params.shift_x + 0.05 + mouse_x))
			* 1.09;
		mlx->f_params.shift_y = ((mlx->f_params.shift_y + mouse_y)) * 1.1;
	}
	else if (key == SCROLL_UP)
	{
		mlx->f_params.ratio *= 0.9;
		mlx->f_params.shift_x = ((mlx->f_params.shift_x - 0.05 + mouse_x))
			* 0.91;
		mlx->f_params.shift_y = ((mlx->f_params.shift_y + mouse_y)) * 0.9;
	}
}

void	mouse_controls(int key, int x, int y, t_mlx *mlx)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (((double)x - WIDTH / 2) * mlx->pixel.x_value) / 9.5;
	mouse_y = (((double)y - HEIGHT / 2) * mlx->pixel.y_value) / 9.5;
	if (ft_strcmp_frctl(mlx->f_params.name, JULIA) == 0
		|| ft_strcmp_frctl(mlx->f_params.name, MULTIBROT) == 0)
	{
		if (key == SCROLL_DOWN)
		{
			mlx->f_params.ratio *= 1.1;
			mlx->f_params.shift_x = ((mlx->f_params.shift_x + mouse_x)) * 1.1;
			mlx->f_params.shift_y = ((mlx->f_params.shift_y + mouse_y)) * 1.1;
		}
		else if (key == SCROLL_UP)
		{
			mlx->f_params.ratio *= 0.9;
			mlx->f_params.shift_x = ((mlx->f_params.shift_x + mouse_x)) * 0.9;
			mlx->f_params.shift_y = ((mlx->f_params.shift_y + mouse_y)) * 0.9;
		}
	}
	if (ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) == 0)
		mouse_controls2(key, x, y, mlx);
	image_refresh(mlx);
}
