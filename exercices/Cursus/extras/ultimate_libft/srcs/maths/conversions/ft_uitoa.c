/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:07 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Transform an unsigned number into a string.
 * 
 * @returns
 * - The string version of an unsigned number.
*/
char	*ft_uitoa(uint64_t n)
{
	uint64_t	nb;
	char		*cpy;
	int			digits;

	digits = 1;
	nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		digits++;
	}
	cpy = malloc(sizeof(char) * digits + 1);
	if (!cpy)
		return (NULL);
	cpy[digits--] = '\0';
	while (digits >= 0)
	{
		cpy[digits--] = n % 10 + '0';
		n /= 10;
	}
	return (cpy);
}
