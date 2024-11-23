/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:52:22 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/23 18:59:05 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count, int limit)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < limit)
	{
		write(1, &s[i], 1);
		*count += 1;
		i++;
	}
}

void	ft_putunbr(int *count, unsigned long n)
{
	if (n > 9)
		ft_putunbr(count, n / 10);
	n = n % 10 + '0';
	*count += 1;
	write(1, &n, 1);
}

void	ft_putnbr(int *count, long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(count, n / 10);
	n = n % 10 + '0';
	*count += 1;
	write(1, &n, 1);
}

void	hexa_print(size_t nb, t_struct v, char x)
{
	char *str;
	size_t nb_cpy;
	
	nb_cpy = nb;
	if (x = 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	
	while (nb > 0)
	{
		nb_cpy = nb;
		while (nb_cpy >= 16)
			nb_cpy /= 16;
		write (1, &str[nb], 1);
		nb /= 16;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
