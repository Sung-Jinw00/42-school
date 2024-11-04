/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:33:27 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (n-- >= 0)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	else
	{
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

/* #include <stdio.h>

int main(void)
{
	char *dest = malloc(30);
	char src[] = "Hello World";
	void *destv = dest;
	const void *srcv = src;

	printf("%s\n", (char *)ft_memmove(destv, srcv, 5));
	return(0);
} */
