/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:50 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Copy n bytes of src at the end of dst.
 * 
 * @note
 * - Guarantee to NUL-terminate the result if dsize is at least greater than
 * the len of dst.*/
/**
 * - Both src and dst must be NUL-terminated.*/
/**
 * - If dst or src are NULL, the strings won't be modified.
 * 
 * 
 * @param dst The string that will be modified.
 * @param src The string that will be added.
 * @param dsize The number of bytes of src that will be copied in dst.
 * 
 * @return
 * - If dsize isn't greater that the len of dst, dst won't be modified, and the
 * function returns the len of dsize + the len of src.*/
/**
 * - Else, the function returns the final len of the concatenated string.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	unsigned int	i;
	unsigned int	len_trunc;
	unsigned int	len_dest;

	len_dest = ft_strlen(dst);
	if (dsize <= len_dest)
		return (dsize + ft_strlen(src));
	len_trunc = ft_strlen(dst) + ft_strlen(src);
	i = -1;
	while (dst && src && src[++i] != '\0' && i < dsize - len_dest - 1)
		dst[len_dest + i] = src[i];
	dst[len_dest + i] = '\0';
	return (len_trunc);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest1[100] = "Hello ";
	char src[] = "World";
	unsigned int size = 8;

	printf("%zu\n", ft_strlcat(dest1, src, size));
	puts(dest1);
	return (0);
} */