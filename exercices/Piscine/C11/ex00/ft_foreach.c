/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:05:14 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 13:16:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <unistd.h>

void	ft_putnbr(int n)
{
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
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/* #include <stdio.h>
#include <limits.h>

		write (1, "\n", 1);

int	main(void)
{
	int tab1[6] = {INT_MIN, -146, 0, 237, 724, INT_MAX};
	int tab2[1] = {0};
	int tab3[5] = {-78432478, -146, -237, -724, -0};

	printf("tab 1 :\n");
	ft_foreach(tab1, 6, &ft_putnbr);
	printf("tab 2 :\n");
	ft_foreach(tab2, 1, &ft_putnbr);
	printf("tab 3 :\n");
	ft_foreach(tab3, 5, &ft_putnbr);
	return (0);
} */