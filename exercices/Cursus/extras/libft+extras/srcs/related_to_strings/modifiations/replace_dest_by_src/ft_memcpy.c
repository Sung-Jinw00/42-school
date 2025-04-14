/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 02:52:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Copies n bytes from src in dest.
 * 
 * @param dest The string that will be replaced by src.
 * @param src The string that will replace n bytes of src.
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
		*(char *)(dest + i) = *(char *)(src + i);
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