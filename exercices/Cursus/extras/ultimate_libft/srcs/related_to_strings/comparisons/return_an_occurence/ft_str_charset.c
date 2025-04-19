/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:07 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Search for the first iteration of one of the characters of `charset` in `s`.
 *  
 * @param s The string that will be scanned.
 * @param charset The characters to find in s.
 * 
 * @returns
 * - If one of the char in `charset` was found in `s`, it will return the whole
 * section of `s` from this character .*/
/**
 * - Else, it will returns 0.
*/
char	*ft_str_charset(const char *s, char *charset)
{
	int	i;

	i = -1;
	while (s && charset && charset[++i])
		if (ft_strchr(s, charset[i]))
			return ((char *)(s + i));
	return (0);
}
