/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:23 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/14 16:18:07 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digits(int n)
{
	int count;
	
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int	if_plus(int i, t_struct v, int *count)
{
	if (v.str[i] == '+')
	{
		write(1, &v.str[i], 1);
		*count += 1;
		i++;
	}
	return (i);
}
