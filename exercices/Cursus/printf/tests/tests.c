/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:36:34 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/16 22:50:09 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_c(char c)
{
	printf("//////////////////// Tests avec 'c' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10c|\n", c));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10c|\n", c));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10c|\n", c));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10c|\n", c));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010c|\n", c));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010c|\n", c));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% c|\n", c));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% c|\n", c));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+c|\n", c));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+c|\n", c));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#c|\n", c));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#c|\n", c));
	printf("\n\n\n");
}

void	tests_s(char *str)
{
	printf("//////////////////// Tests avec 's' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10s|\n", str));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10s|\n", str));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10s|\n", str));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10s|\n", str));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010s|\n", str));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010s|\n", str));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% s|\n", str));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% s|\n", str));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+s|\n", str));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+s|\n", str));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#s|\n", str));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#s|\n", str));
	printf("\n\n\n");
}

void	tests_d(int nb)
{
	printf("//////////////////// Tests avec 'd' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10d|\n", nb));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10d|\n", nb));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10d|\n", nb));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10d|\n", nb));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010d|\n", nb));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010d|\n", nb));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% d|\n", nb));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% d|\n", nb));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+d|\n", nb));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+d|\n", nb));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#d|\n", nb));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#d|\n", nb));
	printf("\n\n\n");
}

void	tests_i(int i)
{
	printf("//////////////////// Tests avec 'i' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10i|\n", i));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10i|\n", i));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10i|\n", i));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10i|\n", i));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010i|\n", i));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010i|\n", i));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% i|\n", i));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% i|\n", i));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+i|\n", i));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+i|\n", i));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#i|\n", i));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#i|\n", i));
	printf("\n\n\n");
}

void	tests_u(int ui)
{
	printf("//////////////////// Tests avec 'u' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10u|\n", ui));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10u|\n", ui));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10u|\n", ui));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10u|\n", ui));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010u|\n", ui));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010u|\n", ui));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% u|\n", ui));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% u|\n", ui));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+u|\n", ui));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+u|\n", ui));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#u|\n", ui));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#u|\n", ui));
	printf("\n\n\n");
}

void	tests_x(int x)
{
	printf("//////////////////// Tests avec 'x' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10x|\n", x));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10x|\n", x));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10x|\n", x));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10x|\n", x));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010x|\n", x));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010x|\n", x));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% x|\n", x));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% x|\n", x));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+x|\n", x));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+x|\n", x));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#x|\n", x));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#x|\n", x));
	printf("\n\n\n");
}

void	tests_x_maj(int x_maj)
{
	printf("//////////////////// Tests avec 'X' ////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10X|\n", x_maj));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10X|\n", x_maj));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10X|\n", x_maj));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10X|\n", x_maj));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |%010X|\n", x_maj));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010X|\n", x_maj));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% X|\n", x_maj));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% X|\n", x_maj));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+X|\n", x_maj));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+X|\n", x_maj));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#X|\n", x_maj));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#X|\n", x_maj));
	printf("\n\n\n");
}

void	tests_percent(void)
{
	printf("//////////////////// Tests avec '%%'////////////////////\n");
	printf("/////test de champ/////\n");
	printf("original : %d\n", printf("original :   |%10%|\n"));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%10%|\n"));
	printf("\n/////test de champ avec '-'/////\n");
	printf("original : %d\n", printf("original :   |%-10%|\n"));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%-10%|\n"));
	printf("\n/////test de champ avec '0'/////\n");
	printf("original : %d\n", printf("original :   |% 10%|\n"));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%010%|\n"));
	printf("\n/////test de champ avec ' '/////\n");
	printf("original : %d\n", printf("original :   |% %|\n"));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |% %|\n"));
	printf("\n/////test de champ avec '+'/////\n");
	printf("original : %d\n", printf("original :   |%+%|\n"));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%+%|\n"));
	printf("\n/////test de champ avec '#'/////\n");
	printf("original : %d\n", printf("original :   |%#%|\n"));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%#%|\n"));
}