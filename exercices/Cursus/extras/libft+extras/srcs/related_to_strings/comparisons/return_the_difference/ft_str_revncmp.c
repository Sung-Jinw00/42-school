/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_revncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 18:17:03 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * return the difference of a string by comparing n bytes at the end of the
 * string
*/
int	ft_str_revncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (1);
	len_s1 = ft_strlen(s1) - 1;
	len_s2 = ft_strlen(s2) - 1;
	while (len_s1 >= 0 && len_s2 >= 0 && len_s1 >= n && len_s2 >= n
		&& (s1[len_s1] || s2[len_s2]))
	{
		if (s1[len_s1] != s2[len_s2])
			return ((unsigned char)s1[len_s1] - (unsigned char)s2[len_s2]);
		len_s1--;
		len_s2--;
	}
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	char s1[] = "Hello World";
	char s2[] = "Hello World";
	unsigned int n = 13;

	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
} */