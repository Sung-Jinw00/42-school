/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Copies n bytes from src in dest and avoid overlaps.
 * 
 * @param dest The string that will be replaced by src.
 * @param src The string that will replace n bytes of src.
 * @param n The number of bytes srcs will replace.
 * 
 * @return
 * The new dest string.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;
	int	size;

	i = -1;
	size = (int)n;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		while (--size >= 0)
			*(char *)(dest + size) = *(char *)(src + size);
	else
		while (++i < size)
			*(char *)(dest + i) = *(char *)(src + i);
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

#define TEST_FAILED ("C'est faux")
#define TEST_SUCCESS ("C'est valide")

int	main(void)
{
	memmove(((void*)0), ((void*)0), 5);
	ft_memmove(((void*)0), ((void*)0), 5);
	printf("original : %s\ncopie : %s\n", (char *)memmove(((void*)0), \
	((void*)0), 5), (char *)ft_memmove(((void*)0), ((void*)0), 5));
	return(0);
} */
/* printf("%s", TEST_SUCCESS);
	printf("%s", TEST_FAILED);
	printf("original : %s\ncopie : %s\n", (char *)memmove(dst1 + 3, dst1, \
	size), (char *)ft_memmove(dst2 + 3, dst2, size)) */
