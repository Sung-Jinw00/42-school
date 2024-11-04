/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:10 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:11 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little)
		return ((char *)big);
	while (i < len)
	{
		while (big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (0);
}

/* #include <stdio.h>

int main(void)
{
	char str[] = "Hello World, wassup ?";
	char to_find[] = "World";

	printf("%s\n", ft_strnstr(str, to_find, 17));
	return (0);
} */