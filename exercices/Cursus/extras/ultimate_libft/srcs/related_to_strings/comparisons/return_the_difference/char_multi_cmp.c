/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_multi_cmp.c                                   :+:      :+:    :+:   */
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
 * Compares an infinite amout of characters of the restrained ascii table.
 * 
 * @param c The character that will be compared with all the others.
 * @param str_char The string that will contain every char to compare with c.
 * 
 * @note
 * If c is not a character from restained ascii table, or if it's equal to
 * zero, or if str_char is NULL or empty, the function will return 0.
 * 
 * @returns
 * Return the character if a comparison was successful, else it returns 0.
*/
char	multi_charcmp(char c, char *str_char)
{
	int	i;

	if (!ft_isascii(c) || !c || !str_char || !str_char[0])
		return (0);
	i = -1;
	while (str_char[++i])
		if (ft_isascii(str_char[i]) && c == str_char[i])
			return (c);
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