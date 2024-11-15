/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:51:56 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/11 20:32:31 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_iterative_factorial(int nb)
{
	int	nbr;

	nbr = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (nb > 1)
	{
		nbr = nbr * (nb - 1);
		nb--;
	}
	return (nbr);
}

/*int main(void)
{
	printf("%d\n", ft_iterative_factorial(4));
	return (0);
}*/