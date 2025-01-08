/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:34:47 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/08 19:50:29 by locagnio         ###   ########.fr       */
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
	//ft_bzero(, WIDTH * HEIGHT * sizeof(int));
	draw_fractals(mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img_ID, 0, 0);
}

void	mouse_controls(int key, t_mlx *mlx)
{
	if (key == SCROLL_DOWN)
		mlx->f_params.ratio *= 1.1;
	else if (key == SCROLL_UP)
		mlx->f_params.ratio *= 0.9;
	mlx_destroy_image(mlx->init, mlx->img.img_ID);
	mlx->img.img_ID = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	draw_fractals(mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img_ID, 0, 0);
}