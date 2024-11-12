/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/12 23:39:27 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	found_count(va_list args, t_struct v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (v.str[i])
	{
		if (v.str[i] == '%' && (v.str[i + 1] != '-' || v.str[i + 1] != '0'))
			ft_redpill(++i, &count, v, args);
		else
		{
			write(1, &v.str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
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
	va_start(args, str);
	v.arg = malloc(8);
	count = found_count(args, v);
	free(v.arg);
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
	long i = 0;
	long j = 0;
	printf("1copie : %d\n", printf("1copie :   %u %u %u \n", LONG_MIN, 0, -42));
	printf("!copie : %d\n", ft_printf("!copie :   %u %u %u \n", LONG_MIN, 0, -42));
	return (0);
}
