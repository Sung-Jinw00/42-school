/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:24 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 02:48:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Creates a new array of strings by concatenate n strings of 2 array of
 * strings.
 * 
 * @param s1 The first array of strings.
 * @param n_s1 The number of strings from s1 that will be joined.
 * @param s2 The second array of strings.
 * @param n_s2 The number of strings from s2 that will be joined.
 * 
 * @note
 * - Every end of array of strings and the last argument should be NULL to
 * interrupt the function correctly, otherwise, undefined outcome may
 * happened.*/
/**
 * - The free of s1 and s2 is the responsibility of the user.
 * 
 * @return
 * The new joined array of strings.
*/
char	**ft_splitnjoin(char **s1, size_t n1, char **s2, size_t n2)
{
	char	**new_split;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (ft_splitndup(s1, ft_count_words(s1), 0, ft_count_words(s1)));
	else if (!s1 && s2)
		return (ft_splitndup(s2, ft_count_words(s2), 0, ft_count_words(s2)));
	if (n1 > (size_t)ft_count_words(s1))
		n1 = (size_t)ft_count_words(s1);
	if (n2 > (size_t)ft_count_words(s2))
		n2 = (size_t)ft_count_words(s2);
	new_split = malloc(n1 + n2 + 1);
	if (!new_split)
		return (NULL);
	i = -1;
	while (s1[++i] && i < n1)
		new_split[i] = ft_strdup(s1[i]);
	j = 0;
	while (s2[j] && j < n2)
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