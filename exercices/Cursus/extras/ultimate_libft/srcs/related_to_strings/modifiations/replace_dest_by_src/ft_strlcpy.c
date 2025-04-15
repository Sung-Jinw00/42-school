/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:55 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Erase and copy dsize of src in dst.
 * 
 * @param dst the string that will be modified.
 * @param src the string that will be copied in dst.
 * @param dsize the number of characters that will be replaced
 * 
 * @returns
 * The len of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dsize == 0)
		return (len);
	i = -1;
	while (++i < dsize - 1 && src[i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (len);
}

/* #include <stdio.h>

int	main(void)
{
	char dst[14];
	char src[] = "Hello World.";

	printf("%zu\n", ft_strlcpy(dst, src, 15));
	printf("%s\n", dst);
	return(0);
} */