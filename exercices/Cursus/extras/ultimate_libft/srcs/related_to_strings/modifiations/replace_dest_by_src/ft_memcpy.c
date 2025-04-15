/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Copies n bytes from src in dest.
 * 
 * @param dest The string that will be replaced by src.
 * @param src The string that will replace n bytes of dest.
 * @param n The number of bytes srcs will replace.
 * 
 * @note
 * The function may overlaps.
 * 
 * @return
 * The new dest string.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char dest[30];
	char src[] = "Hello World";

	printf("%s\n", (char *)ft_memcpy(dest, src, 5));
	return(0);
} */