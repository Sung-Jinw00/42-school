/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:23:40 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/26 11:54:36 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/do_op.h"

void	ft_add(char *s1, char *s2)
{
	long long	first_nbr;
	long long	second_nbr;

	first_nbr = mini_atoi(s1);
	second_nbr = mini_atoi(s2);
	ft_putnbr(first_nbr + second_nbr);
}

void	ft_sub(char *s1, char *s2)
{
	long long	first_nbr;
	long long	second_nbr;

	first_nbr = mini_atoi(s1);
	second_nbr = mini_atoi(s2);
	ft_putnbr(first_nbr - second_nbr);
}

void	ft_mult(char *s1, char *s2)
{
	long long	first_nbr;
	long long	second_nbr;

	first_nbr = mini_atoi(s1);
	second_nbr = mini_atoi(s2);
	ft_putnbr(first_nbr * second_nbr);
}

void	ft_div(char *s1, char *s2)
{
	long long	first_nbr;
	long long	second_nbr;

	first_nbr = mini_atoi(s1);
	second_nbr = mini_atoi(s2);
	if (second_nbr == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(first_nbr / second_nbr);
}

void	ft_mod(char *s1, char *s2)
{
	long long	first_nbr;
	long long	second_nbr;

	first_nbr = mini_atoi(s1);
	second_nbr = mini_atoi(s2);
	if (second_nbr == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(first_nbr % second_nbr);
}
