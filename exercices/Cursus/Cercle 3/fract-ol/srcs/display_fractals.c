/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:20:19 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/16 19:26:01 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	image_refresh(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img.img_id);
	mlx->img.img_id = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	draw_fractals(mlx);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img_id, 0, 0);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = mlx->img.addr + (y * mlx->img.line_length + x
			* (mlx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	equations(char *fractal_name, t_mlx *mlx)
{
	if (ft_strcmp_frctl(fractal_name, MANDELBROT) == 0)
		return (mandelbrot_equation(mlx->f_params.x, mlx->f_params.y));
	else if (ft_strcmp_frctl(fractal_name, JULIA) == 0)
		return (julia_equation(mlx->f_params.x, mlx->f_params.y,
				mlx->f_params.real, mlx->f_params.im));
	else if (ft_strcmp_frctl(fractal_name, MULTIBROT) == 0)
		return (multibrot_equation(mlx->f_params.x, mlx->f_params.y,
				mlx->f_params.d));
	return (error(RED "\nCannot choose an equation.\n" RESET, mlx), 1);
}

void	draw_fractals(t_mlx *mlx)
{
	mlx->pixel.x = 0;
	mlx->pixel.y = 0;
	mlx->pixel.w_scale = mlx->f_params.ratio * 1.5 / WIDTH;
	mlx->pixel.h_scale = mlx->f_params.ratio / HEIGHT;
	mlx->pixel.w_move = mlx->f_params.shift_x;
	mlx->pixel.h_move = mlx->f_params.shift_y;
	while (mlx->pixel.y < HEIGHT)
	{
		mlx->pixel.x = 0;
		while (mlx->pixel.x < WIDTH)
		{
			mlx->f_params.x = mlx->pixel.x * mlx->pixel.w_scale
				+ mlx->pixel.w_move;
			mlx->f_params.y = mlx->pixel.y * mlx->pixel.h_scale
				+ mlx->pixel.h_move;
			mlx->pixel.color = equations(mlx->f_params.name, mlx);
			my_mlx_pixel_put(mlx, mlx->pixel.x, mlx->pixel.y, mlx->pixel.color);
			mlx->pixel.x++;
		}
		mlx->pixel.y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img.img_id, 0, 0);
}

/* if (mlx->pixel.x == WIDTH / 2 || mlx->pixel.x == WIDTH / 4
	|| mlx->pixel.x == (WIDTH / 4) * 3 || mlx->pixel.y == HEIGHT / 2
	|| mlx->pixel.y == HEIGHT / 4 || mlx->pixel.y == (HEIGHT / 4) * 3)
	mlx->pixel.color = OX_RED;
else */