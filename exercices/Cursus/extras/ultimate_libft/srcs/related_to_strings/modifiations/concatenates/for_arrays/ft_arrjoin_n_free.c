/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin_n_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:24 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 02:53:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Creates a new string by concatenate 2 strings and free whatever used array
 * of strings you want to free.
 * 
 * @param s1 The first sring.
 * @param s2 The second sring.
 * @param tab_to_free :*/
/**
 * - If tab_to_free = 1, s1 will be freed.*/
/**
 * - If tab_to_free = 2, s2 will be freed.*/
/**
 * - If tab_to_free = 12 (1 and 2), both s1 and s2 will be freed.
 * 
 * @return
 * The new joined array of strings.
*/
char	**ft_arrjoin_n_free(char **s1, char **s2, int tab_to_free)
{
	char	**array;

	array = ft_arrjoin(s1, s2);
	if (tab_to_free == 1)
		return (free_array(&s1), array);
	else if (tab_to_free == 2)
		return (free_array(&s2), array);
	else if (tab_to_free == 12)
		return (free_array(&s1), free_array(&s2), array);
	return (array);
}

/* #include <stdio.h>

int	main(void)
{
	char *s1 = "Hello ";
	char *s2 = "World";

	s1 = ft_strjoin(s1, s2);
	printf("%s\n", s1);
	free(s1);
	return (0);
} */