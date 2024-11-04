/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:47:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/30 20:55:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_vals(long *nb, int *i, int *sign)
{
	long	nbr;

	if (*nb < 0)
	{
		*sign = 1;
		*i++;
		*nb = -*nb;
	}
	if (*nb == 0)
		*i++;
	nbr = *nb;
	while (nbr > 0)
	{
		nbr /= 10;
		*i++;
	}
}

char	*itoa(int n)
{
	char	*cpy;
	int		i;
	long	nb;
	int		sign;

	i = -1;
	sign = 0;
	nb = n;
	init_vals(&nb, &i, &sign);
	cpy = malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);
	cpy[i] = 0;
	while (i >= sign)
	{
		cpy[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	if (sign == 1)
		cpy[0] = '-';
	return (cpy);
}

/* #include <stdio.h>

int	main(void)
{
	char *cpy1 = itoa(-2147483648);
	char *cpy2 = itoa(-2147483647);
	char *cpy3 = itoa(-1);
	char *cpy4 = itoa(-0);
	char *cpy5 = itoa(1);
	char *cpy6 = itoa(2147483647);

	printf("%s\n", cpy1);
	free(cpy1);
	printf("%s\n", cpy2);
	free(cpy2);
	printf("%s\n", cpy3);
	free(cpy3);
	printf("%s\n", cpy4);
	free(cpy4);
	printf("%s\n", cpy5);
	free(cpy5);
	printf("%s\n", cpy6);
	free(cpy6);
	return (0);
} */