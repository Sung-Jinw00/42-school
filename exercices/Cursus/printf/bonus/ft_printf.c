/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/14 19:11:48 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_istring(int *str)
{
	int i;

	i = 0;
	while (str[i])
		str[i++] = 0;
}

void	set_cstring(char *str)
{
	int i;

	i = 0;
	while (str[i])
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
	set_istring(v.flag_order);
	set_cstring(v.flags_found);
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
	printf("1copie : %d\n", printf("1copie :   %p\n", NULL));
	printf("!copie : %d\n", ft_printf("!copie :   %p\n", NULL));
	return (0);
}
