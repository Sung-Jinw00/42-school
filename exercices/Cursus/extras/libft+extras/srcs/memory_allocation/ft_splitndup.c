/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:29:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"


/**
 * @brief
 * Create a dublicate of an array of strings, at start tab, up to end tab.
 * 
 * @param split The array of strings that will be duplicated.
 * @param len_split The len of the array of strings that will be duplicated. 
 * @param start The starting string of the duplication.
 * @param end The end string of the duplication.
 * 
 * @returns
 * - If start >= end, or if split is NULL, the function returns NULL. */
/**
 * - Else, the function will return the duplicated array of end - start strings.
*/
char	**ft_splitndup(char **split, int len_split, int start, int end)
{
	char	**dup;
	int		i;
	int		len;

	if (end > len_split)
		end = len_split;
	if (start >= end || !split)
		return (NULL);
	len = end - start + 1;
	dup = (char **)malloc(sizeof(char *) * len);
	if (!dup)
		return (NULL);
	i = 0;
	while (start < end)
		dup[i++] = ft_strdup(split[start++]);
	dup[i] = NULL;
	return (dup);
}
