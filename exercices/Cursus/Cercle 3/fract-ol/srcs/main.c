/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:31:17 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/03 17:07:20 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac >= 2)
	{
		init_shift(&mlx, ac, av);
		mlx.window = mlx_new_window(mlx.init, WIDTH, HEIGHT, mlx.f_params.name);
		mlx.img.img_ID = mlx_new_image(mlx.init, WIDTH, HEIGHT);
		if (!mlx.window || !mlx.img.img_ID)
		{
			mlx_destroy_image(mlx.init, mlx.img.img_ID);
			mlx_destroy_window(mlx.init, mlx.window);
			error(RED"Cannot generate image or window.\n"RESET);
		}
		mlx.img.addr = mlx_get_data_addr(mlx.img.img_ID, &mlx.img.bits_per_pixel,\
		&mlx.img.line_length, &mlx.img.endian);
		if (!mlx.img.addr)
			error(RED"Cannot collect data addr.\n"RESET);
		draw_fractals(&mlx);
		mlx_hook(mlx.window, DestroyNotify, KeyReleaseMask, quit, &mlx);
		mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.img_ID, 0, 0);
		mlx_key_hook(mlx.window, deal_key, &mlx);
		//mlx_mouse_hook(mlx.window, deal_mouse, &mlx);
		mlx_loop(mlx.init);
	}
	return (0);
}
