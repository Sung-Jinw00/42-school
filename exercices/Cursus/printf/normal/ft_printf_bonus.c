/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/18 00:44:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	len_field_nb2(t_struct v, int len_val)
{
	int			zeros;
	long long	nb;

	zeros = 0;
	nb = *(long long *)v.arg;
	if (ft_strchr(v.flag_order, '.'))
	{
		if (nb < 0)
			nb = -nb;
		zeros = v.nb2 - ft_digits(nb);
		if (v.nb2 > ft_digits(nb))
			len_val += zeros;
	}
	return (len_val);
}

int	printfzeronb(int v)
{
	while (v > 0)
	{
		write(1, "0", 1);
		v--;
	}
	return (0);
}

t_struct	ft_preprint_nb(t_struct v)
{
	int	zeros;
	int	sign;

	sign = 0;
	v.zerosnb = 0;
	if (*(long long *)v.arg < 0)
		sign = 1;
	zeros = v.nb2 - ft_digits(*(long long *)v.arg) + sign;
	if (ft_strchr(v.flag_order, '.') && zeros > 0)
		v.zerosnb = zeros;
	return (v);
}

char	*strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = -1;
	dup = (char *)malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	while (++i < n)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	v;
	int			count;
	int			i;

	if (!str)
		return (0);
	i = 0;
	v.arg = 0;
	v.str = str;
	v.nb1 = 0;
	v.nb2 = 0;
	v.zerosnb = 0;
	while (i < 7)
		v.flag_order[i++] = 0;
	va_start(args, str);
	v.arg = malloc(8);
	count = print_this_bs(args, v);
	free(v.arg);
	va_end(args);
	return (count);
}

/* #include "../tests/tests.h"
#include <limits.h>

void	tests_point(void)
{
	printf("//////////////////// Tests avec 's' ////////////////////\n");
	printf("/////test de champ avec '.'/////\n");
	printf("original : %d\n", printf("original :   |%3.1s|\n", NULL));
	fflush(stdout);
	printf("copie    : %d\n", ft_printf("copie    :   |%3.1s|\n", NULL));
	printf("\n\n\n");
}

int main(void)
{
	//tests_c(0);
	//tests_s(NULL);
	//tests_d(-128);
	//tests_i(-128);
	//tests_u(-128);
	//tests_x(-128);
	//tests_x_maj(-128);
	//tests_percent();
	tests_point();
	return (0);
} */

/*
- [OUTPUT] ft_printf("%3.1s", NULL)
- [OUTPUT] ft_printf("%9.1s", NULL)
- [OUTPUT] ft_printf("%-3.1s", NULL)
- [OUTPUT] ft_printf("%-9.1s", NULL)
- [OUTPUT] ft_printf("%50.2s", NULL)*/