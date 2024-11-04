/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:25:57 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/30 20:52:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t dsize)
{
	unsigned int	i;
	unsigned int	len_trunc;
	unsigned int	len_dest;

	i = 0;
	len_dest = ft_strlen(dst) + 1;
	if (dsize <= len_dest)
		return (dsize + ft_strlen(src));
	len_trunc = ft_strlen(dst) + ft_strlen(src) + 1;
	while (src[i] != '\0' && i < dsize - len_dest - 1)
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_trunc);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest1[100] = "Hello ";
	char dest2[100] = "Hello ";
	char src[] = "World";
	unsigned int size = 11;

	printf("%u\n", ft_strlcat(dest1, src, size));
	puts(dest1);
	printf("%zu\n", strlcat(dest2, src, size));
	puts(dest2);
	return (0);
}*/