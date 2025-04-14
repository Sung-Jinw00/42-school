/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:24 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 02:09:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Creates a new array of strings by concatenate 2 array of
 * strings.
 * 
 * @param s1 The first array of strings.
 * @param s2 The second array of strings.
 * 
 * @note
 * Every end of array of strings and the last argument should be NULL to
 * interrupt the function correctly, otherwise, undefined outcome may happened.
 * 
 * @return
 * The new joined array of strings.
*/
char	**ft_splitjoin(char **s1, char **s2)
{
	char	**new_split;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (ft_splitdup(s1));
	else if (!s1 && s2)
		return (ft_splitdup(s2));
	i = -1;
	j = 0;
	len = ft_count_words(s1) + ft_count_words(s2) + 1;
	new_split = malloc(len);
	if (!new_split)
		return (NULL);
	while (s1[++i])
		new_split[i] = ft_strdup(s1[i]);
	while (s2[j])
		new_split[i++] = ft_strdup(s2[j++]);
	new_split[i] = NULL;
	return (new_split);
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