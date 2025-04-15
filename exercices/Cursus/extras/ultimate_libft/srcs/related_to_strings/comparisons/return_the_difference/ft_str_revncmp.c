/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_revncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Compares n characters of 2 strings from the end.
 * 
 * @param n : */
/**
 * - If n <= 0, the function will return 1.*/
/**
 * - Else, the function will compare n bytes of both strings from the end.
 * 
 * @returns
 * Return 0 if a comparison was successful, else it returns 1.
*/
int	ft_str_revncmp(const char *s1, const char *s2, int n)
{
	int	len_s1;
	int	len_s2;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2 || n <= 0)
		return (1);
	len_s1 = (int)ft_strlen(s1) - 1;
	len_s2 = (int)ft_strlen(s2) - 1;
	if (len_s2 > len_s1)
		return (1);
	while (len_s1 >= 0 && len_s2 >= 0 && (s1[len_s1] || s2[len_s2]) && n-- >= 0)
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