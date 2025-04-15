/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bouble_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:39:14 by marvin            #+#    #+#             */
/*   Updated: 2025/01/19 15:39:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static bool	correct_format(char *str_char)
{
	int	i;

	i = 0;
	while (str_char[i])
	{
		if (ft_isnum(str_char[i]))
			i++;
		else if (!ft_strncmp(str_char + i, ", ", 2) && i != 0)
			i += 2;
		else
			return (0);
	}
	return (1);
}

/**
 * @brief
 * Free an infinite of number of arguments.
 * 
 * @param to_free :*/
/**
 * - The string "to_free" must follow the format : "n1, n2, ..., nn".*/
/**
 * - If n = 1, it will free a string (*str).*/
/**
 * - If n = 2, it will free an array of strings (**str).*/
/**
 * @note
 * - The last argument should be NULL to interrupt the function correctly,
 * otherwise, undefined outcome may happened.*/
/**
 * - If the format of to_free isn't respected, or if it's NULL or empty,
 * nothing will be freed.
 * 
 * @param str is an pointer on an array of strings.
*/
void	multi_free(char *to_free, ...)
{
	va_list	args;
	void	*ptrn;
	int		*tabs_to_free;
	int		i;

	tabs_to_free = NULL;
	if (to_free && correct_format(to_free))
		tabs_to_free = strchar_to_strint(to_free);
	va_start(args, to_free);
	ptrn = va_arg(args, void *);
	i = 0;
	while (ptrn)
	{
		if (tabs_to_free && tabs_to_free[i] == 1 && ptrn)
			ft_free((char **)&ptrn);
		if (tabs_to_free && tabs_to_free[i] == 2 && (char **)ptrn)
			free_array((char ***)&ptrn);
		ptrn = va_arg(args, void *);
		i++;
	}
	free(tabs_to_free);
	va_end(args);
}
