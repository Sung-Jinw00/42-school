/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:35:51 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/31 19:40:47 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
