/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:57:10 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief Search for a string into another one at most len bytes.
 * 
 * @param s The string that will be used to search to_find.
 * @param to_find The string that will be searched in s.
 * @param len The n bytes that will be checked.
 * 
 * @returns
 * 1 if to_find was found. 0 if to_find wasn't found.
*/
int	ft_strnchr(const char *s, const char *to_find, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && i < len)
	{
		while (s[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == 0)
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}
