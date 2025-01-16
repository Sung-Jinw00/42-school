/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:07:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/16 19:29:59 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

char	*set_args(char *arg, int arg_nb, t_mlx *mlx)
{
	int	i;

	if (!arg && arg_nb == 1)
		error(RED "\nNo name specified !\n" RESET, mlx);
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
	else if (!ft_strcmp_frctl(arg, MULTIBROT))
		return (MULTIBROT);
	else if (arg_nb == 1)
		return (error(RED "\nInvalid name !\n" RESET, mlx), NULL);
	if (!ft_strcmp_frctl(arg, PRESET) && arg_nb == 2)
		return (PRESET);
	else
		return (NULL);
}

void	set_fractal_datas2(t_mlx *mlx, int ac, char **av)
{
	if ((!ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) && ac <= 2)
		|| (!ft_strcmp_frctl(mlx->f_params.name, MULTIBROT) && ac <= 4 && av[2]
			&& av[2][0] == '1' && !av[2][1]))
	{
		mlx->f_params.shift_x = -2.5;
		mlx->f_params.shift_y = -(2.5 / 2);
		mlx->pixel.x_value = 0.00232857;
		if (!ft_strcmp_frctl(mlx->f_params.name, MULTIBROT))
			mlx->f_params.d = 2;
	}
	else if (!ft_strcmp_frctl(mlx->f_params.name, MULTIBROT) && ac <= 4)
	{
		mlx->f_params.ratio = 3;
		mlx->f_params.shift_x = -2.5 + 0.3;
		mlx->f_params.shift_y = -(2.5 / 2) - 0.2;
		if (ac <= 4 && !ft_strcmp_frctl(set_args(av[2], 2, mlx), PRESET))
			multibrot_presets(mlx, av[3][0]);
		else if (ac == 3)
			mlx->f_params.d = ft_atod(av[2]) + 1;
		else
			mlx->f_params.d = 4;
		mlx->pixel.x_value = (0.00268571 + 0.00232857) / 2;
	}
	mlx->divizor = 9.5;
	mlx->max_iter = MAX_ITER;
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
		mlx->pixel.x_value = 0.00268571;
	}
	else if ((!ft_strcmp_frctl(mlx->f_params.name, MANDELBROT) && ac <= 2)
		|| (!ft_strcmp_frctl(mlx->f_params.name, MULTIBROT) && ac <= 4))
		set_fractal_datas2(mlx, ac, av);
	mlx->pixel.y_value = 0.00268571;
}
