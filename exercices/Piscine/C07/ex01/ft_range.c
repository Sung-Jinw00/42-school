/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:24:04 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/16 11:33:52 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stddef.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	int	*cpy;
	int	len_cpy;
	int	i;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr (n / 10);
	n = n % 10 + '0';
	write (1, &n, 1);
} */
int	*ft_range(int min, int max)
{
	i = 0;
	if (min >= max)
		return (0);
	len_cpy = max - min;
	cpy = (int *)malloc(sizeof(int) * len_cpy);
	if (!cpy)
		return (NULL);
	while (min < max)
	{
		cpy[i] = min;
		i++;
		min++;
	}
	return (cpy);
}

/* int	main(void)
{
	int *cpy;
	int i = 0;
	int max = 100;

	cpy = ft_range(1, max);
	while (i < max - 1)
	{
		ft_putnbr(cpy[i]);
		if (cpy[i] % 10 == 0)
			write (1, "\n", 1);
		else if (cpy[i] < max - 1)
		{
			write (1, ", ", 2);
			if (cpy[i] < 10)
				write (1, " ", 1);
		}
		i++;
	}
	free (cpy);
	return (0);
} */
