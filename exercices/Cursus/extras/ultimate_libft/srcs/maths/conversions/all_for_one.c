/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief Converts a numeric value into a string representation.
 * 
 * @param value     Pointer to the value to be converted.
 * @param precision Number of digits after the decimal point (used for floats
 * only).
 * @param type      Type of the value. Must be one of : */
/**
 * 					- "signed"   → for signed integers (int64_t) */
/**
 * 					- "unsigned" → for unsigned integers (uint64_t) */
/**
 * 					- "float"    → for floating-point numbers (long double)
 * 
 * @note
 * - If `type` is NULL or doesn't match one of the supported types, the
 * function returns NULL. */
/**
 *- For floating-point types, if `precision < 1`, the decimal point and digits
 after it are omitted.
 * 
 * @return
 * - A newly allocated string representing the number, or
 * - NULL if the type is invalid.
 */
char	*all_for_one(void *value, int precision, char *type)
{
	if (!type)
		return (NULL);
	else if (!ft_strcmp(type, FT_SIGNED))
		return (ft_itoa(*(int64_t *)value));
	else if (!ft_strcmp(type, FT_UNSIGNED))
		return (ft_uitoa(*(uint64_t *)value));
	else if (!ft_strcmp(type, FT_FLOAT))
		return (ft_ftoa(*(long double *)value, precision));
	return (NULL);
}
