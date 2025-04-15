/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:26:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static int	erroru64(char *str)
{
	return (ft_multi_write(2, str, ": invalid argument\n", NULL), 0);
}

static int	cmp_u64(char *nptr)
{
	size_t	len_max;
	size_t	len_nptr;

	len_nptr = ft_strlen(nptr);
	len_max = ft_strlen(FT_UINT64_MAX);
	return (nptr[0] == '-' || len_nptr > len_max
		|| (len_nptr == len_max && ft_strcmp(nptr, FT_UINT64_MAX) > 0));
}

/**
 * @brief
 * Transform a number in a string into an uint64 (unsigned long long int).
 * 
 * The function checks the string to see if the number isn't bigger than an
 * int64.
 * 
 * @returns
 * - If nptr = NULL, if the number is outside the limits of a uint64, or if the
 * casual requirements of atoi aren't respected, the function returns 0.*/
/**
 * - Else, it returns the uint64 (unsigned long long int) version of a string
 * of numbers.
*/
uint64_t	ft_atoui64(char *nptr)
{
	int			i;
	uint64_t	result;

	if (!nptr || cmp_u64(ft_remove_from_string(nptr, " \t+", 0)))
		return (erroru64(nptr));
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			return (ft_write(2, "ft_atoui64 : nb is negative\n"), 0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	return (result);
}
