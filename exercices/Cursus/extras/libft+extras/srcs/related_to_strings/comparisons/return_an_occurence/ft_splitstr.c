/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:42 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 02:12:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Search for the first iteration of str in split.
 *  
 * @param split The array of strings that will be scanned.
 * @param str The string to find in split.
 * 
 * @returns
 * - If split is NULL of empty, or if str is NULL, the function will returns
 * NULL.*/
/**
 * - If str was found in split, it will return a memory allocated duplicate of
 * the whole section of split from str.*/
/**
 * - Else, it will returns NULL.
*/
char	**ft_split_strsrch(char **split, char *str)
{
	int	i;

	if (!split || !split[0] || !str)
		return (NULL);
	i = -1;
	while (split[++i])
		if (!ft_strcmp(split[i], str))
			return (ft_splitdup((char **)(split + i)));
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
