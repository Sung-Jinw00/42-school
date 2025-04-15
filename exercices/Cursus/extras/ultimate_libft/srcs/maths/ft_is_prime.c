/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:38 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Tells if a number is a prime number or not.
 * 
 * @returns
 * - 1 if the number is a prime number.*/
/**
 * - Else 0.
*/
int	ft_is_prime(int nb)
{
	int	i;

	i = nb / 2 + 1;
	if (nb <= 1)
		return (0);
	while (--i > 1)
		if (nb % i == 0)
			return (0);
	return (1);
}

/*int main(void)
{
	printf("%d\n", ft_is_prime(0));
	return (0);
}*/