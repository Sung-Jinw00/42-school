/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 21:24:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

static int	error64(void)
{
	ft_write(2, "ft_atold : nb outside the limits of a long long\n");
	return (0);
}

static int	cmp_64(char *nptr)
{
	size_t	len_max;
	size_t	len_min;

	len_max = ft_strlen(INT64_MAX_ATOI);
	len_min = ft_strlen(INT64_MIN_ATOI);
	if ((nptr[0] != '-' && ft_strlen(nptr) > len_max)
		|| (nptr[0] == '-' && ft_strlen(nptr) > len_min))
		return (1);
	else if (nptr[0] != '-' && ft_strlen(nptr) == len_max)
	{
		if (ft_strcmp(nptr, INT64_MAX_ATOI) > 0)
			return (1);
	}
	else if (nptr[0] == '-' && ft_strlen(nptr) == len_min)
	{
		if (ft_strcmp(nptr, INT64_MIN_ATOI) > 0)
			return (1);
	}
	return (0);
}

/**
 * @brief
 * Transform a number in a string into an long long int.
 * 
 * @returns
 * - If nptr = NULL, or if the casual requirements of
 * atoi aren't respected, the function returns 0.*/
/**
 * - Else, it returns the long long int version of a string of numbers.
*/
long long	ft_atold(char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	if (!nptr || cmp_64(ft_remove_from_string(nptr, " \t+", 0)))
		return (error64());
	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

/* #include <stdio.h>

int	main(void)
{
	const char nptr[] = "   +1234ab567";

	printf("%d\n", ft_atoi(nptr));
	return(0);

} */