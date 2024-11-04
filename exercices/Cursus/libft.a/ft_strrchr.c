/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:14 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:14 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	const char *s = "Hello world";
	int c = 'H';

	s = ft_strrchr(s, c);
	printf("%s\n", s);
	return (0);
} */
