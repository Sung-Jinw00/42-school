/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:33:00 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/12 19:39:32 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_vals(long nb, int *sign, const char *base)
{
	int	i;
	int	digits;

	i = 0;
	digits = 1;
	if (nb < 0)
	{
		nb = -nb;
		*sign = 1;
	}
	while (nb >= (long)ft_strlen(base))
	{
		nb /= ft_strlen(base);
		digits++;
	}
	i = digits + *sign;
	return (i);
}

char	*ft_itoa_base(int n, const char *base)
{
	char	*cpy;
	long	nb;
	int		i;
	int		sign;

	nb = n;
	sign = 0;
	i = init_vals(nb, &sign, base);
	if (nb < 0)
		nb = -nb;
	cpy = malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);
	if (sign == 1)
		cpy[0] = '-';
	cpy[i--] = '\0';
	while (i >= sign)
	{
		cpy[i] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
		i--;
	}
	return (cpy);
}
/* #include <stdio.h>

int main(void)
{
	char str[] = "      +-++-50";
	char base[] = "0123456789ABCDEF";

	printf("%d\n", ft_atoi_base(str, base));
	return (0);
} */