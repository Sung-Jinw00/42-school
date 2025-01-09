/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:10:54 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 18:06:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	set_mlx_datas(t_mlx *mlx)
{
	mlx->init = mlx_init();
	if (!mlx->init)
		error(RED"\nCannot initiate mlx.\n"RESET, mlx);
	mlx->window = mlx_new_window(mlx->init, WIDTH, HEIGHT, mlx->f_params.name);
	mlx->img.img_ID = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	if (!mlx->window || !mlx->img.img_ID)
	{
		mlx_destroy_image(mlx->init, mlx->img.img_ID);
		mlx_destroy_window(mlx->init, mlx->window);
		error(RED"\nCannot generate image or window.\n"RESET, mlx);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ID, &mlx->img.bits_per_pixel,\
	&mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
		error(RED"\nCannot collect data addr.\n"RESET, mlx);
}
