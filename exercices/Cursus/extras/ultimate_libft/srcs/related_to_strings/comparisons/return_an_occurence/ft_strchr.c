/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:42 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Search for the first iteration of c in s.
 *  
 * @param s The string that will be scanned.
 * @param c The character to find in s.
 * 
 * @returns
 * - If c was found in s, it will return the whole section of s from c.*/
/**
 * - Else, it will returns 0.
*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s && s[++i])
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	const char *s = NULL;

	s = ft_strchr(s, 'H');
	printf("%s\n", s);
	return (0);
} */
