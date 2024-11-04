/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:33:11 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
			return (i);
		i++;
	}
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	const char *tab1 = "Hello";
	const char *tab2 = "world";
	int c;
	const void *s1 = tab1;
	const void *s2 = tab2;

	c = ft_memcmp(s1, s2, 3);
	printf("%d\n", c);
	return(0);
} */