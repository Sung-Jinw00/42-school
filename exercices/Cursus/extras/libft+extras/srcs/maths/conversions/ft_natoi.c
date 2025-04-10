/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:23:02 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 17:29:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Transform a number in a string into an integer by starting at i.
 * 
 * @returns
 * - If nptr = NULL, or if i is not in nptr, or if the casual requirements of
 * atoi aren't respected, the function returns 0.*/
/**
 * - Else, it returns the integer version of a string of numbers.
*/
int	ft_natoi(const char *nptr, int *i)
{
	int		sign;
	long	result;

	if (!nptr || *i >= (int)ft_strlen(nptr) || *i < 0)
		return (0);
	sign = 1;
	result = 0;
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		*i += 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -sign;
		*i += 1;
	}
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		result = result * 10 + nptr[*i] - '0';
		*i += 1;
	}
	return (result * sign);
}
