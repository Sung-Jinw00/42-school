/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:07:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 20:05:36 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbrot_equation(double x, double y)
{
	unsigned int i;
	double		r;
	double		im_tmp;
	double		r2;

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

char	*set_args(char *arg, int arg_nb, t_mlx *mlx)
{
	int i;

	if (!arg && arg_nb == 1)
		error(RED"\nNo name specified !\n"RESET, mlx);
	if (!arg && arg_nb == 2)
		return (NULL);
	i = 0;
		if (arg[i] >= 'a' && arg[i] <= 'z')
			arg[i] -= 32;
		while (arg[++i])
			if (arg[i] >= 'A' && arg[i] <= 'Z')
				arg[i] += 32;
		if (!ft_strcmp_frctl(arg, MANDELBROT))
			return (MANDELBROT);
		else if (!ft_strcmp_frctl(arg, JULIA))
			return (JULIA);
		else if (arg_nb == 1)
			return (error(RED"\nInvalid name !\n"\
			CYAN BOLD"Theses are the valid names to display a fractal :\n"\
			RESET GREEN"- \"Mandelbrot\"\n- \"Julia\"\n"RESET, mlx), NULL);
	if (!ft_strcmp_frctl(arg, PRESET) && arg_nb == 2)
		return (PRESET);
	else
		return (NULL);
}

void	set_fractal_datas(t_mlx *mlx, int ac, char **av)
{
	mlx->f_params.name = set_args(av[1], 1, mlx);
	mlx->f_params.ratio = 2.5;
	mlx->ac = ac;
	mlx->av = av;
	if (!ft_strcmp_frctl(mlx->f_params.name, JULIA) && ac <= 4)
	{
		julia_presets(mlx, '1');
		if (ac <= 4 && !ft_strcmp_frctl(set_args(av[2], 2, mlx), PRESET))
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
	else if (!ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) && ac <= 2)
	{
		mlx->f_params.shift_x = -2.5;
		mlx->f_params.shift_y = -(2.5 / 2);	
	}
}
