/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/13 23:36:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief Transform any number into a string.
 * 
 * @param value A pointer on the value that will be turned into a string.
 * @param precision For float numbers only, the amount of digits after the
 * coma.*/
/**
 * If precision < 1, no number after the coma will be added,
 * as well as the coma itself. 
 * @param type :*/
/**
 * - The function will converts if type equal to "signed", "unsigned"
 * or "float".*/
/**
 * - If the type is wrong, the value will be equal to NULL.
 * 
 * 
 * @returns
 * - If type is NULL or if the type doesn't match, the function will
 * return NULL.*/
/**
 * - Else, it returns the string of a number.
*/
char	*all_for_one(void *value, int precision, char *type)
{
	if (!type)
		return (NULL);
	else if (!ft_strcmp(type, TYPE_SIGNED))
		return (ft_itoa(*(int64_t *)value));
	else if (!ft_strcmp(type, TYPE_UNSIGNED))
		return (ft_uitoa(*(uint64_t *)value));
	else if (!ft_strcmp(type, TYPE_FLOAT))
		return (ft_ftoa(*(long double *)value, precision));
	return (NULL);
}
