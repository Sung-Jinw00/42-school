/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
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
 * Duplicates an array of strings.
 * 
 * @returns
 * - If `array` is NULL, the function returns NULL.*/
/**
 * - Else, the function will return the duplicated array of strings.
*/
char	**ft_arrdup(char **array)
{
	char	**dup;
	int		i;

	if (!array)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (ft_count_words(array) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		dup[i] = ft_strdup(array[i]);
		if (!dup[i])
			return (free_array(&dup), NULL);
	}
	dup[i] = NULL;
	return (dup);
}

/* #include <stdio.h>

int	main(void)
{
	char src[] = "Hello";
	char *cpy;

	cpy = ft_strdup(src);
	printf("adresse de src : %p\nsrc : %s\nadresse de cpy : %p\ncpy : %s\n",\
	src, src, cpy, cpy);
	free (cpy);
	return (0);
} */