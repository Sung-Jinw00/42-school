/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:57:21 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 14:57:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Reverse an array of strings.
 * 
 * @param array The array of strings that will be reversed.
 * @param to_malloc 1 if the user wants a reversed array of strings with a
 * different memory adress than `array`. 0 if not.
 * 
 * @return
 * The new reversed array of strings.
*/
char	**ft_revarray(char **array, bool to_malloc)
{
	int		i;
	int		j;
	char	**dup;

	if (!array)
		return (NULL);
	i = -1;
	j = ft_count_words(array);
	if (!to_malloc)
	{
		while (++i < --j)
			ft_swap(&array[i], &array[j], sizeof(char *));
		return (array);
	}
	dup = ft_arrdup(array);
	if (!dup)
		return (NULL);
	while (++i < --j)
		ft_swap(&dup[i], &dup[j], sizeof(char *));
	return (dup);
}
