/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:33:00 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/13 19:42:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	init_vals(long nb, const char *base)
{
	int	i;
	int	digits;

	i = 0;
	digits = 1;
	while (nb >= (long)ft_strlen(base))
	{
		nb /= ft_strlen(base);
		digits++;
	}
	i = digits;
	return (i);
}

char	*ft_itoa_base(long long n, const char *base)
{
	char		*cpy;
	long long	nb;
	int			i;

	if (n < 0)
		n = (n + (long)INT_MAX * 2 + 2);
	nb = n;
	i = init_vals(nb, base);
	cpy = malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);

	cpy[i--] = '\0';
	while (i >= 0)
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