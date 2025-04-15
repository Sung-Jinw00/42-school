/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Create a duplicate of an array of strings, at start tab, up to end tab.
 * 
 * @param array The array of strings that will be duplicated.
 * @param len_array The len of `array` that will be duplicated. 
 * @param start The starting string of the duplication.
 * @param end The end string of the duplication.
 * 
 * @returns
 * - If start >= end, or if `arr` is NULL, the function returns NULL. */
/**
 * - Else, the function will return the duplicated array of end - start strings.
*/
char	**ft_arrndup(char **array, int len_array, int start, int end)
{
	char	**dup;
	int		i;
	int		len;

	if (end > len_array)
		end = len_array;
	if (start >= end || !array)
		return (NULL);
	len = end - start + 1;
	dup = (char **)malloc(sizeof(char *) * len);
	if (!dup)
		return (NULL);
	i = 0;
	while (start < end)
		dup[i++] = ft_strdup(array[start++]);
	dup[i] = NULL;
	return (dup);
}
