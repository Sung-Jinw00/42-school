/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:25 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/18 10:48:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Join an infinite amount of strings.
 * 
 * @note
 * - The last argument should be NULL to interrupt the function correctly,
 * otherwise, undefined outcome may happened. */
/**
 * - If one of your strings is NULL, the function will stop at this string,
 * be careful.*/
/**
 * - The free of the strings are the responsibility of the user.
 * 
 * @returns
 * The new joined string, or the duplicate of s1 if there's no other argument.
*/
char	*multi_join(char *s1, ...)
{
	va_list	args;
	char	*arg;
	char	*new_string;

	if (!s1)
		return (NULL);
	va_start(args, s1);
	arg = va_arg(args, char *);
	if (!arg)
		return (va_end(args), ft_strdup(s1));
	new_string = ft_strjoin(s1, arg);
	if (!new_string)
		return (ft_write(2, "fail join\n"), NULL);
	arg = va_arg(args, char *);
	while (arg)
	{
		new_string = ft_strjoin_n_free(new_string, arg, 1);
		if (!new_string)
			return (ft_write(2, "fail join and free\n"), NULL);
		arg = va_arg(args, char *);
	}
	va_end(args);
	return (new_string);
}
