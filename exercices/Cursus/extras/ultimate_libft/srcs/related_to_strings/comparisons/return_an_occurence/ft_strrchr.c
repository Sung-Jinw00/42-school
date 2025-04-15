/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:14 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Search for the last iteration of c in s.
 *  
 * @param s The string that will be scanned.
 * @param c The character to find in s.
 * 
 * @returns
 * - If c was found in s, it will return the whole section of s from c.*/
/**
 * - Else, it will returns 0.
*/
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (--len >= 0)
		if (s[len] == (char)c)
			return ((char *)s + len);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	const char *s = "Hello world";

	s = ft_strrchr(s, 't' + 256);
	printf("%s\n", s);
	return (0);
} */
