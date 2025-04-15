/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:44:19 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 12:44:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Reverse a string.
 * 
 * @param str The string that will be reversed.
 * @param to_malloc 1 if the user wants a reversed string with a different
 * memory adress than str. 0 if not.
 * 
 * @return
 * The new reversed string.
*/
char	*ft_strrev(char *str, bool to_malloc)
{
	int		i;
	int		j;
	char	*dup;

	if (!str)
		return (NULL);
	i = -1;
	j = ft_strlen(str);
	if (!to_malloc)
	{
		while (++i < --j)
			ft_swap(&str[i], &str[j], sizeof(char));
		return (str);
	}
	dup = ft_strdup(str);
	if (!dup)
		return (NULL);
	while (++i < --j)
		ft_swap(&dup[i], &dup[j], sizeof(char));
	return (dup);
}
