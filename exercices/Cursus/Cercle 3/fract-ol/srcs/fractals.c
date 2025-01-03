/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:35:51 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/03 18:18:32 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbrot_equation(double x, double y)
{
	unsigned int i;
	double r;
	double im_tmp;
	double	r2;

	r = 0;
	i = 0;
	im_tmp = 0;
	while (i < MAX_ITER)
	{
		r2 = r * r - im_tmp * im_tmp + x;
		im_tmp = 2 * r * im_tmp + y;
		r = r2;
		if ((r * r + im_tmp * im_tmp) > 4)
			return (rotate_hue((double)i));
		i++;
	}
	return (OX_BLACK);
}

int julia_equation(double x, double y, double c_re, double c_im)
{
    unsigned int i;
    double r;
    double im_tmp;
    double r2;

    r = x;
    im_tmp = y;
    i = 0;
    while (i < MAX_ITER)
    {
        r2 = r * r - im_tmp * im_tmp + c_re;
        im_tmp = 2 * r * im_tmp + c_im;
        r = r2;
        if ((r * r + im_tmp * im_tmp) > 4)
            return (rotate_hue((double)i));
        i++;
    }
    return (OX_BLACK);
}

void	julia_presets(t_mlx *mlx, char preset_choice)
{
	if (preset_choice == '1')
	{
		mlx->f_params.real = -0.70176;
		mlx->f_params.im = -0.3842;
	}
	else if (preset_choice == '2')
	{
		mlx->f_params.real = -0.835;
		mlx->f_params.im = -0.2321;
	}
	else if (preset_choice == '3')
	{
		mlx->f_params.real = -0.4;
		mlx->f_params.im = 0.615;
	}
	else if (preset_choice == '4')
	{
		mlx->f_params.real = 0.285;
		mlx->f_params.im = 0.01;
	}
	else if (preset_choice == '5')
	{
		mlx->f_params.real = 0.4;
		mlx->f_params.im = 0.4;
	}
}
