/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_strsrch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:42 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Search for the first iteration of `str` in `array`.
 *  
 * @param array The array of strings that will be scanned.
 * @param str The string to find in `array`.
 * 
 * @returns
 * - If `array` is NULL of empty, or if `str` is NULL, the function will returns
 * NULL.*/
/**
 * - If `str` was found in `array`, it will return a memory allocated duplicate
 * of the whole section of `array` from `str`.*/
/**
 * - Else, it will returns NULL.
*/
char	**ft_arr_strsrch(char **array, char *str)
{
	int	i;

	if (!array || !array[0] || !str)
		return (NULL);
	i = -1;
	while (array[++i])
		if (!ft_strcmp(array[i], str))
			return (ft_arrdup((char **)(array + i)));
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char *s = NULL;

	s = ft_strchr(s, 'H');
	printf("%s\n", s);
	return (0);
} */
