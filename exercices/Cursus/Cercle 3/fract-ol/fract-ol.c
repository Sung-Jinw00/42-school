/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:39:57 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/31 20:19:04 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

unsigned int rotate_hue(double iter);

int	deal_key(int key, void *param)
{
	printf("%d\n", key);
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
	if (fractal_name == "Mandelbrot")
		return (mandelbrot_equation(f_params.x, f_params.y));
	else if ((fractal_name == "Julia"))
		return (julia_equation(f_params.x, f_params.y));
}

void	draw_fractals(t_mlx *mlx, char *fractal_name)
{
	double ratio;
	double c_re;
    double c_im; 

	c_re = -0.70176;
    c_im = 0.3842; 
	ratio = 2.5;
	mlx->pixel.x = 0;
	mlx->pixel.y = 0;
	mlx->pixel.w_scale = ratio * 1.5 / WIDTH;
	mlx->pixel.h_scale = ratio / HEIGHT;
	mlx->pixel.w_move = -ratio;
	mlx->pixel.h_move = -(ratio / 2);
	while (mlx->pixel.y < HEIGHT)
	{
		mlx->pixel.x = 0;
		while (mlx->pixel.x < WIDTH)
		{
			mlx->f_params.x = mlx->pixel.x * mlx->pixel.w_scale + mlx->pixel.w_move;
			mlx->f_params.y = mlx->pixel.y * mlx->pixel.h_scale + mlx->pixel.h_move;
			mlx->pixel.color = equations(fractal_name, mlx->f_params);
			my_mlx_pixel_put(mlx, mlx->pixel.x, mlx->pixel.y, mlx->pixel.color);
			mlx->pixel.x++;
		}
		mlx->pixel.y++;
	}
}

int main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.f_params.name = ft_fratal_name(av[1]);
	mlx.init = mlx_init();
	if (!mlx.init)
		error(RED"Cannot initiate mlx.\n"RESET);
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
	draw_fractals(&mlx, mlx.f_params.name);
	mlx_put_image_to_window(mlx.init, mlx.window, mlx.img.img_ID, 0, 0);
	//mlx_key_hook(mlx.window, deal_key, 0);
	mlx_mouse_hook(mlx.window, deal_key, 0);
	mlx_hook(mlx.window, CLOSE_WINDOW, 0, deal_key, mlx.init);
	mlx_loop(mlx.init);
	return (0);
}
