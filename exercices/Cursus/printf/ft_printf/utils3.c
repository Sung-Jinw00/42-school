/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:08:53 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/24 21:12:17 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
}

void	hexa_print(unsigned int nb, t_struct v, char x)
{
	char	*str;

	if (x == 'x' && srch_flag(v.flags, '#'))
		write(1, "0x", 2);
	else if (x == 'X' && srch_flag(v.flags, '#'))
		write(1, "0X", 2);
	while (v.zeros-- > 0)
		write(1, "0", 1);
	if (x == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	ft_putnbr_base(nb, str);
}

int	ft_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}
