/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:34:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 19:27:04 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	arrow_controls(int key, t_mlx *mlx)
{
	if (key == XK_Left)
		mlx->f_params.shift_x += 0.01;
	else if (key == XK_Right)
		mlx->f_params.shift_x -= 0.01;
	else if (key == XK_Up)
		mlx->f_params.shift_y += 0.01;
	else if (key == XK_Down)
		mlx->f_params.shift_y -= 0.01;
	else if (key == XK_r)
	{
		set_fractal_datas(mlx, mlx->ac, mlx->av);
		mlx->f_params.ratio = 2.5;
		mlx->f_params.shift_y = -(2.5 / 2);	
		if (ft_strcmp_frctl(mlx->f_params.name, JULIA) == 0)
			mlx->f_params.shift_x = -2.5 + 0.6;
		else if (ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) == 0)
			mlx->f_params.shift_x = -2.5;
	}
	draw_fractals(mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img_ID, 0, 0);
}

void	mouse_controls(int key, t_mlx *mlx)
{
	double	adapter;

	adapter = 0;
	if (ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) == 0)
		adapter = 0.025;
	if (key == SCROLL_DOWN)
	{
		mlx->f_params.ratio *= 1.1;
		mlx->f_params.shift_x = (mlx->f_params.shift_x + adapter) * 1.1;
		mlx->f_params.shift_y *= 1.1;
	}
	else if (key == SCROLL_UP)
	{
		mlx->f_params.ratio *= 0.9;
		mlx->f_params.shift_x = (mlx->f_params.shift_x - adapter) * 0.9;
		mlx->f_params.shift_y *= 0.9;
	}
	mlx_destroy_image(mlx->init, mlx->img.img_ID);
	mlx->img.img_ID = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	draw_fractals(mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img_ID, 0, 0);
}
