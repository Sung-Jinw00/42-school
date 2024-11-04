/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:47:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/20 11:39:29 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*itoa(int nbr)
{
	char *	cpy;
	int i;
	long nb;
	long n;
	int sign;
	
	i = -1;
	sign = 0;
	nb = nbr;
	if (nb < 0)
	{
		sign = 1;
		i++;
		nb = -nb;
	}
	if (nb == 0)
		i++;
	n = nb;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
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

#include <stdio.h>

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
}