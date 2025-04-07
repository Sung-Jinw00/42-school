/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:25 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 20:48:58 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Creates a new string by concatenate 2 strings and free whatever used string
 * you want to free.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @param tab_to_free :*/
/**
 * - If tab_to_free = 1, s1 will be freed.*/
/**
 * - If tab_to_free = 2, s2 will be freed.*/
/**
 * - If tab_to_free = 12 (1 and 2), both s1 and s2 will be freed.
 * 
 * @return
 * The new joined string.
*/
char	*ft_strjoin_n_free(char *s1, char *s2, int tab_to_free)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_string = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!new_string)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	if (tab_to_free == 1)
		free(s1);
	else if (tab_to_free == 2)
		free(s2);
	else if (tab_to_free == 12)
		return (free(s1), free(s2), new_string);
	return (new_string);
}
