/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_splitjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:25 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 01:02:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Join an infinite amount of array of strings.
 * 
 * @note
 * Every end of array of strings and the last argument should be NULL to
 * interrupt the function correctly, otherwise, undefined outcome may happened.
 * 
 * @returns
 * The new joined array of strings, or the duplicate of s1 if there's no
 * other argument.
*/
char	**multi_splitjoin(char **s1, ...)
{
	va_list	args;
	char	**arg;
	char	**new_split;

	if (!s1)
		return (NULL);
	va_start(args, s1);
	arg = va_arg(args, char **);
	if (!arg)
		return (va_end(args), ft_splitdup(s1));
	new_split = ft_splitjoin(s1, arg);
	if (!new_split)
		return (ft_putstr_fd(2, "fail join\n"), NULL);
	arg = va_arg(args, char **);
	while (arg)
	{
		new_split = ft_splitjoin_n_free(new_split, arg, 1);
		if (!new_split)
			return (ft_putstr_fd(2, "fail join and free\n"), NULL);
		arg = va_arg(args, char **);
	}
	va_end(args);
	return (new_split);
}
