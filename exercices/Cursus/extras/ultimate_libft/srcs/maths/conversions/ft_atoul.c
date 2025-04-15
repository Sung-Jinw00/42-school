/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Transform a number in a string into an unsigned long int.
 * 
 * @returns
 * - If nptr = NULL, if the result is outside the limits of an unsigned long
 * int, or if the casual requirements of atoi aren't respected, the function
 * returns 0.*/
/**
 * - Else, it returns the unsigned long int version of a string of numbers.
*/
unsigned long	ft_atoul(char *nptr)
{
	int			i;
	uint64_t	result;

	if (!nptr)
		return (0);
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			return (ft_write(2, "ft_atoul : nb is negative\n"), 0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	if (result > ULONG_MAX)
		return (ft_write(2, "ft_atoul : nb greater than unsigned long\n"), 0);
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	const char nptr[] = "   +1234ab567";

	printf("%d\n", ft_atoi(nptr));
	return(0);

} */