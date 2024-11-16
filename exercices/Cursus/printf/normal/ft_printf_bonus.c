/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/17 00:22:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	set_string(char *str)
{
	int	i;

	i = 0;
	while (i < 7)
		str[i++] = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	v;
	int			count;

	if (!str)
		return (0);
	v.arg = 0;
	v.str = str;
	v.nb1 = 0;
	v.nb2 = 0;
	set_string(v.flag_order);
	va_start(args, str);
	v.arg = malloc(8);
	count = print_this_bs(args, v);
	free(v.arg);
	va_end(args);
	return (count);
}

/* #include "../tests/tests.h"

int main(void)
{
	tests_c(0);
	tests_s(NULL);
	tests_d(-128);
	tests_i(-128);
	tests_u(-128);
	tests_x(-128);
	tests_x_maj(-128);
	tests_percent();
	return (0);
} */
