/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:14:34 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 17:20:21 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	error(char *error_message, t_mlx *mlx)
{
	perror(error_message);
	free(mlx);
	help_message();
	exit(EXIT_FAILURE);
}

void	help_message2(void)
{
	ft_printf(" 5 pretty different variants of Julia's fratal.\n"
				"\n\t[4] ");
	ft_printf(UNDERLINE "Close the window :\n" RESET "\t\tYou can close the ");
	ft_printf("window by pressing " BOLD "\"esc\"" RESET " or by " BOLD "clicking");
	ft_printf(" on the cross" RESET " on the top right border of the\n\t\t");
	ft_printf("window.\n" RESET "\n " ITALIC "(Tip : Open a new terminal");
	ft_printf(" to keep a visual on this guide if you need it !)\n" RESET);
}

void	help_message(void)
{
	ft_printf(" Hello there !\n\n\n This is how you use this program ");
	ft_printf("properly :\n\t[1] " UNDERLINE "Compile the program :\n" RESET);
	ft_printf("\t\tYou should have created");
	ft_printf(" the " BOLD "./fract-ol" RESET " executable.\n\n\t" RESET);
	ft_printf("[2] " UNDERLINE "Choose your fractal, but how ?" RESET "\n\t\t");
	ft_printf("Theses are " BOLD "the valid names" RESET " that you will use as ");
	ft_printf("your " BOLD "first argument" RESET " :\n\t\t- " BOLD "Mandelbrot");
	ft_printf(RESET "\n\t\t- " BOLD "Julia" RESET "\n\n\tYou can write it however");
	ft_printf(" you want as long as the word is " BOLD "correctly spelled" RESET);
	ft_printf(" (with uppercases or lowercases).\n");
	ft_printf("\t\t" UNDERLINE "exs :" RESET "\n\t\t - mandebrot/MANDELBROT/");
	ft_printf("MaNdElBrOt/MANDELbrot...\n\t\t - julia/JULIA/JuLiA/JUlia...");
	ft_printf("\n\n\t[3] (optional) ");
	ft_printf(UNDERLINE "Add personalized settings !" RESET "\n\t\t- You can ");
	ft_printf("specify a" BOLD " real variable " RESET "and an " BOLD "imaginary ");
	ft_printf("variable " RESET "when you choose the " BOLD "Julia fractal.\n");
	ft_printf(RESET "\t\tTheses will be respectively your " BOLD "2nd and 3rd ");
	ft_printf("arguments.\n" RESET "\n \t\t- Always on " BOLD "Julia's fractal");
	ft_printf(RESET ", you can type \"preset\" as the " BOLD "2nd argument");
	ft_printf(RESET " and a number between " BOLD "1 and 5" RESET " as\n\t\t  ");
	ft_printf("your " BOLD "3rd argument" RESET " to chose between");
	help_message2();
	ft_printf("\n\n Now, you're ready to do all the tests ");
	ft_printf("that you want, " BOLD "enjoy !\n" RESET);
}
