/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 02:47:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Duplicates an array of strings.
 * 
 * @returns
 * - If split is NULL, the function returns NULL.*/
/**
 * - Else, the function will return the duplicate array of strings.
*/
char	**ft_splitdup(char **split)
{
	char	**dup;
	int		i;

	if (!split)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (ft_count_words(split) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (split[++i])
	{
		dup[i] = ft_strdup(split[i]);
		if (!dup[i])
			return (free_dbl_tab(&dup), NULL);
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