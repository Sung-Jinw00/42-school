/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:26:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static int	error64(void)
{
	ft_write(2, "ft_atoi64 : nb outside the limits of a uint64\n");
	return (0);
}

static int	cmp_64(char *nptr)
{
	size_t	len_max;
	size_t	len_min;

	len_max = ft_strlen(FT_INT64_MAX);
	len_min = ft_strlen(FT_INT64_MIN);
	if ((nptr[0] != '-' && ft_strlen(nptr) > len_max)
		|| (nptr[0] == '-' && ft_strlen(nptr) > len_min))
		return (1);
	else if (nptr[0] != '-' && ft_strlen(nptr) == len_max
		&& ft_strcmp(nptr, FT_INT64_MAX) > 0)
		return (1);
	else if (nptr[0] == '-' && ft_strlen(nptr) == len_min
		&& ft_strcmp(nptr, FT_INT64_MIN) > 0)
		return (1);
	return (0);
}

/**
 * @brief
 * Transform a number in a string into an int64 (long long int).
 * 
 * The function checks the string to see if the number isn't bigger than an
 * int64.
 * 
 * @returns
 * - If nptr = NULL, or if the casual requirements of
 * atoi aren't respected, the function returns 0.*/
/**
 * - Else, it returns the int64 (long long int) version of a string of numbers.
*/
int64_t	ft_atoi64(char *nptr)
{
	int		i;
	int		sign;
	int64_t	result;

	if (!nptr || cmp_64(ft_remove_from_string(nptr, " \t+", 0)))
		return (error64());
	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -sign;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	return (result * sign);
}
