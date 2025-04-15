/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrclen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:59 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * The len of s when :*/
/**
 * - It reaches the last iteration of c in s.*/
/**
 * - It reaches the start of s.
*/
size_t	ft_strrclen(const char *s, char c)
{
	int		i;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s) - 1;
	i = len_s;
	while (i >= 0 && s[i] != c)
		i--;
	return (len_s - i);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "Yeppi";

	printf("%zu\n", ft_strlen(str));
	return(0);
} */
