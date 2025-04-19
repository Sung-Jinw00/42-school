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
 * - If one of your strings is NULL, the function will stop at this string,
 * be careful.*/
/**
 * - If `to_free` is NULL or empty, nothing will be freed.
 * 
 * @param str is an pointer on an array of strings.
*/
void	multi_free(char *to_free, ...)
{
	va_list	args;
	void	*ptrn;
	int		*tabs_to_free;
	int		len_arrint;
	int		i;

	tabs_to_free = NULL;
	len_arrint = 0;
	if (to_free)
		tabs_to_free = str_to_arrint(to_free, &len_arrint);
	va_start(args, to_free);
	ptrn = va_arg(args, void *);
	i = 0;
	while (ptrn && tabs_to_free && i < len_arrint)
	{
		if (tabs_to_free[i] == 1 && ptrn)
			ft_free((char **)&ptrn);
		if (tabs_to_free[i] == 2 && (char **)ptrn)
			free_array((char ***)&ptrn);
		ptrn = va_arg(args, void *);
		i++;
	}
	free(tabs_to_free);
	va_end(args);
}
