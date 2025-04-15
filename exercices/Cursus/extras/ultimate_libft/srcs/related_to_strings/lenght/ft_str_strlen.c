/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_strlen.c                                    :+:      :+:    :+:   */
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
 * The len of s1 when :*/
/**
 * - It reaches the first iteration of s2 in s1.*/
/**
 * - It reaches the end of s1.
*/
size_t	ft_str_strlen(const char *s1, char *s2)
{
	size_t	i;
	size_t	len_s2;

	if (!s1)
		return (0);
	else if (!s2)
		return (ft_strlen(s1));
	i = 0;
	len_s2 = ft_strlen(s2);
	while (s1[i] && ft_strncmp(s1 + i, s2, len_s2))
		i++;
	return (i);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "Yeppi";

	printf("%zu\n", ft_strlen(str));
	return(0);
} */
