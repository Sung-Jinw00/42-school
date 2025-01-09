/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:21:08 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 19:05:07 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	quit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img.img_ID);
	mlx_destroy_window(mlx->init, mlx->window);
	mlx_loop_end(mlx->init);
	free(mlx->init);
	free(mlx);
	exit(EXIT_SUCCESS);
}

int mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	x += 7 - y;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_controls(button, mlx);
	return (0 * x);
}

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

void	mlx_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, DestroyNotify, KeyReleaseMask, quit, mlx);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	mlx_hook(mlx->window, KeyPress, KeyPressMask, deal_key, mlx);
}