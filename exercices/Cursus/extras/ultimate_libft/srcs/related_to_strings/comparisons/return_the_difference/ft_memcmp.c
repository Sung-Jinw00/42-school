/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:11 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Compares n characters of 2 arguments.
 * 
 * @param n : */
/**
 * - If n <= 0, or if one of the strings are NULL, the function will return 1.*/
/**
 * - Else, the function will compare n bytes of both strings from the end.
 * 
 * @returns
 * Return 0 if a comparison was successful, else it returns 1.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (n <= 0 || (!s1 && s2) || (s1 && !s2))
		return (1);
	i = -1;
	while (++i < n)
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	char *s1 = "atoms\0\0\0\0";
	char *s2 = "atoms\0abc";
	size_t size = 8;
	int i1 = ((memcmp(s1, s2, size) > 0) ? 1 : ((memcmp(s1, s2, size) < 0) \
	? -1 : 0));
	int i2 = ((ft_memcmp(s1, s2, size) > 0) ? 1 : ((ft_memcmp(s1, s2, size) \
	< 0) ? -1 : 0));
	printf("i1 : %d\ni2 : %d\n", i1, i2);
	if (i1 == i2)
		printf("c'est bon");
	return (0);
} */