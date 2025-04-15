/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_cmp.c                                    :+:      :+:    :+:   */
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
 * Compares an infinite amout of strings and return the string if it
 * was successful.
 * 
 * @note
 * - The last argument should be NULL, otherwise, the function may have an
 * undefined behavior.*/
/**
 * - If s1 is NULL, the function will return NULL.
 * 
 * @returns
 * Return the string if a comparison was successful, else it returns NULL.
*/
char	*get_multi_cmp(const char *s1, ...)
{
	const char	*arg;
	va_list		args;

	if (!s1)
		return (NULL);
	va_start(args, s1);
	arg = va_arg(args, const char *);
	while (arg)
	{
		if (!ft_strcmp(s1, arg))
			return (va_end(args), (char *)arg);
		else
			arg = va_arg(args, const char *);
	}
	va_end(args);
	return (NULL);
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