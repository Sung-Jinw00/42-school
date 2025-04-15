/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_for_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief Transform a number in a string into any type of integers wished.
 * 
 * @param nptr The string that will be converted.
 * @param value A pointer on the value where the user want to receive the result
 * of the function.
 * @param type :*/
/**
 * - The function will converts if type equal to "int", "unsigned int",
 *  "long" ,"unsigned long", "long long", "unsigned long long", "double" or
 * "float".*/
/**
 * - If the type is wrong, the value will be equal to zero.
 * 
 * @returns
 * - If nptr = NULL, if the result is outside the limits of the type chosen,
 * or if the casual requirements of atoi aren't respected, the function
 * returns 0.*/
/**
 * - Else, it returns the integer version of a string of numbers.
*/
void	one_for_all(char *nptr, void *value, char *type)
{
	if (!nptr || !type)
		*(int *)value = 0;
	else if (!ft_strcmp(type, FT_INT))
		*(int *)value = ft_atoi(nptr);
	else if (!ft_strcmp(type, FT_UINT))
		*(unsigned int *)value = ft_atoui(nptr);
	else if (!ft_strcmp(type, FT_LONG))
		*(long *)value = ft_atol(nptr);
	else if (!ft_strcmp(type, FT_ULONG))
		*(unsigned long *)value = ft_atoul(nptr);
	else if (!ft_strcmp(type, FT_LLONG))
		*(int64_t *)value = ft_atoi64(nptr);
	else if (!ft_strcmp(type, FT_ULLONG))
		*(uint64_t *)value = ft_atoui64(nptr);
	else if (!ft_strcmp(type, FT_DOUBLE))
		*(double *)value = ft_atod(nptr);
	else if (!ft_strcmp(type, FT_FLOAT))
		*(float *)value = ft_atof(nptr);
	else
		*(int *)value = 0;
}

/* #include <stdio.h>

int	main(void)
{
	const char nptr[] = "   +1234ab567";

	printf("%d\n", ft_atoi(nptr)), value = &nb, value;
	return(0);

} */
