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
 * Scans n bytes of an argument for the first instance of c.
 *  
 * @param s The array of strings that will be scanned.
 * @param c The string to find in split.
 * @param n The amount of bytes that wiill be checked.
 * 
 * @returns
 * - If c was found in s, it will return the whole section of s from c.*/
/**
 * - Else, it will returns NULL.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	const char *tab = "Hello world";
	int c = 'o';
	const void *s = tab;

	s = ft_memchr(s, c, 3);
	printf("%s\n", (unsigned char *)s);
	return(0);
} */
