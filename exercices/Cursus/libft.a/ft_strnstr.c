/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:14:12 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/30 18:31:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little)
		return (big);
	while (i < len)
	{
		while (big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return (big + i - j);
		j = 0;
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main(void)
{
	char str[] = "Hello World, wassup ?";
	char to_find[] = "World";

	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}*/