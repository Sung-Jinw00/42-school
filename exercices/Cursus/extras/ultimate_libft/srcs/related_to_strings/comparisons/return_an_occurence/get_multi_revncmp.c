/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_revncmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/18 10:52:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Compares an infinite amout of n characters of strings from the end and
 * return the string if it was successful.
 * 
 * @param n : */
/**
 * - If n < 0, the function will take a lenght for each string in
 * the following format "s1, s2, n_s2, s3, n_s3,..., sn, n_sn".*/
/**
 * - Else if n == 0, the function will return NULL.*/
/**
 * - Else, n will be applied for every string from the end.
 * 
 * @note
 * - The last argument should be NULL, otherwise, the function may have an
 * undefined behavior.*/
/**
 * - If one of your strings is NULL, the function will stop at this string,
 * be careful.
 * 
 * @returns
 * Return the string if a comparison was successful, else it returns NULL.
*/
char	*get_multi_revncmp(int n, const char *s1, ...)
{
	const char	*arg;
	va_list		args;
	size_t		n_sn;

	if (!n)
		return (NULL);
	va_start(args, s1);
	arg = va_arg(args, const char *);
	if (n < 0)
		n_sn = va_arg(args, size_t);
	while (arg)
	{
		if (n > 0 && !ft_str_revncmp(s1, arg, n))
			return (va_end(args), (char *)arg);
		else if (n < 0 && !ft_str_revncmp(s1, arg, n_sn))
			return (va_end(args), (char *)arg);
		else
			arg = va_arg(args, const char *);
		if (n < 0)
			n_sn = va_arg(args, size_t);
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