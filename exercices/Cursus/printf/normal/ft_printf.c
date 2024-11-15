/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/14 23:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	found_count(va_list args, t_struct v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (v.str[i])
	{
		if (v.str[i] == '%')
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

/* #include <stdio.h>

int main(void)
{
	long i = 0;
	long j = 0;
	printf("1copie : %d\n", printf("1copie :   %.10d\n", 46));
	printf("!copie : %d\n", ft_printf("!copie :   %p\n", NULL));
	printf("%c\n", 'l');
	printf("%010c\n\n", 'l');
	printf("|%---10d|\n", 46);
	printf("|%.10d|\n\n", 46);
	printf("%.10i\n", 46);
	printf("%010i\n\n", 46);
	char str = 'H';
	printf("%.10s\n", "Hello :3");
	printf("%010s\n\n", "Hello :3");
	printf("%.10p\n", &str);
	printf("%010p\n\n", &str);
	printf("%.10u\n", -36);
	printf("%010u\n\n", -36);
	printf("%.10x\n", 373453);
	printf("%010x\n\n", 373453);
	printf("%.10X\n", 373453);
	printf("%010X\n\n", 373453);
	printf("%.10%\n");
	printf("%010%\n\n");
	return (0);
} */
