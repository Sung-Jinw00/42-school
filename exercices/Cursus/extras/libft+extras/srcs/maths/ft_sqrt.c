/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:36:44 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 14:38:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Calculates the square root of a number.
 * 
 * @returns
 * - The square root of a number if it exists.*/
/**
 * - Else 0.
*/
int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (++i <= nb / 2)
		if (i * i == nb)
			return (i);
	return (0);
}

/*int main(void)
{
	printf("%d\n", ft_sqrt(16));
	return (0);
}*/
