/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:25 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

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
	char	*str;

	str = ft_strjoin(s1, s2);
	if (tab_to_free == 1)
		return (free(s1), str);
	else if (tab_to_free == 2)
		return (free(s2), str);
	else if (tab_to_free == 12)
		return (free(s1), free(s2), str);
	return (str);
}
