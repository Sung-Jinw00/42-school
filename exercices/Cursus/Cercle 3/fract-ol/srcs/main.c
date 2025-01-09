/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:06 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 19:05:25 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int main(int ac, char **av)
{
	t_mlx	*mlx;

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
	return (free(mlx->init), free(mlx), 0);
}