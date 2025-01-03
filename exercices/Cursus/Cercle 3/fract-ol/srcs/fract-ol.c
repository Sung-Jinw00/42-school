/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:39:57 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/03 17:57:41 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	quit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img.img_ID);
	mlx_destroy_window(mlx->init, mlx->window);
	mlx_loop_end (mlx->init);
	free(mlx->init);
	exit(EXIT_SUCCESS);
}

/* int deal_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == LEFT_CLICK || button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, mlx);
	return (0);
} */

int	deal_key(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
	{
		quit(mlx);
	}
	else if (key == XK_Left || key == XK_Right
		|| key == XK_Up || key == XK_Down)
		arrow_controls(key, mlx);
	return (0);
}
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = mlx->img.addr + (y * mlx->img.line_length + x * \
	(mlx->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	equations(char *fractal_name, t_fl_params f_params)
{
	if (ft_strcmp(fractal_name, MANDELBROT) == 0)
		return (mandelbrot_equation(f_params.x, f_params.y));
	else if (ft_strcmp(fractal_name, JULIA) == 0)
		return (julia_equation(f_params.x, f_params.y, f_params.real, f_params.im));
	return (error(RED"Cannot choose an equation.\n"RESET), 1);
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
			mlx->f_params.x = mlx->pixel.x * mlx->pixel.w_scale + mlx->pixel.w_move;
			mlx->f_params.y = mlx->pixel.y * mlx->pixel.h_scale + mlx->pixel.h_move;
			mlx->pixel.color = equations(mlx->f_params.name, mlx->f_params);
			my_mlx_pixel_put(mlx, mlx->pixel.x, mlx->pixel.y, mlx->pixel.color);
			mlx->pixel.x++;
		}
		mlx->pixel.y++;
	}
}

void	init_shift(t_mlx *mlx, int ac, char **av)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		error(RED"Cannot initiate mlx.\n"RESET);
	mlx->f_params.name = set_args(av[1], 1);
	mlx->f_params.ratio = 2.5;
	if (!ft_strcmp(mlx->f_params.name, JULIA))
	{
		if (ac >= 3 && !ft_strcmp(set_args(av[2], 2), PRESET))
			julia_presets(mlx, av[3][0]);
		else
		{
			if (ac >= 3 && av[2])
				mlx->f_params.real = ft_atod(av[2]);
			if (ac >= 4 && av[3])
				mlx->f_params.im = ft_atod(av[3]);
		}
		mlx->f_params.shift_x = -2.5 + 0.6;
		mlx->f_params.shift_y = -(2.5 / 2);	
	}
	else if (!ft_strcmp(mlx->f_params.name, MANDELBROT))
	{
		mlx->f_params.shift_x = -2.5;
		mlx->f_params.shift_y = -(2.5 / 2);	
	}
}
