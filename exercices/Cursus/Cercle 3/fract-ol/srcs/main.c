/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/15 17:26:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	free_all(t_mlx *mlx)
{
	if (mlx->img.img_ID)
		mlx_destroy_image(mlx->init, mlx->img.img_ID);
	if (mlx->window)
		mlx_destroy_window(mlx->init, mlx->window);
	if (mlx->init)
		mlx_destroy_display(mlx->init);
	free(mlx->init);
	free(mlx);
}

int	main(int ac, char **av)
{
	t_mlx *mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (ac >= 2 && ac <= 4)
	{
		set_fractal_datas(mlx, ac, av);
		set_mlx_datas(mlx);
		draw_fractals(mlx);
		mlx_hooks(mlx);
		mlx_loop(mlx->init);
	}
	else
		help_message();
	return (free_all(mlx), 0);
}
