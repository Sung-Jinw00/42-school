/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arrjoin_n_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:25 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 01:04:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

int	has_to_be_freed(t_majnf v, int *tab_inc)
{
	while (v.tabs_to_free[*tab_inc] < v.cur_str && *tab_inc < v.tab_len - 1)
		(*tab_inc)++;
	if (*tab_inc == v.tab_len - 1 && v.tabs_to_free[*tab_inc] < v.cur_str)
		return (0);
	if (v.tabs_to_free[*tab_inc] == v.cur_str)
		return (1);
	return (0);
}

char	**multi_arrjoin_n_free2(t_majnf v)
{
	if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
		free_array(&v.arg);
	if (!v.new_arr)
		return (ft_putstr_fd(2, "fail join\n"), NULL);
	v.arg = va_arg(v.args, char **);
	v.cur_str = 2;
	while (v.arg)
	{
		v.new_arr = ft_arrjoin_n_free(v.new_arr, v.arg, 1);
		if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
			free_array(&v.arg);
		if (!v.new_arr)
			return (ft_putstr_fd(2, "fail join and free\n"), NULL);
		v.arg = va_arg(v.args, char **);
		v.cur_str++;
	}
	va_end(v.args);
	free(v.tabs_to_free);
	return (v.new_arr);
}

/**
 * @brief
 * Join an infinite amount of array of strings and free the wished tabs.
 * 
 * @param to_free : */
/**
 * - Each numbers represent the position of each string that should be freed,
 * starting at position zero.*/
/**
 * - If the number exceeds the limits of the amount of strings, they will be
 * ignored.*/
/**
 * - If `to_free` is NULL or empty, no string will be freed.
 * 
 * @note
 * - Every end of array of strings and the last argument should be NULL to
 * interrupt the function correctly, otherwise, undefined outcome may
 * happened.*/
/**
 * - If one of your strings is NULL, the function will stop at this string,
 * be careful.
 * 
 * @returns
 * The new joined array of strings, or the duplicate of s1 if there's no other
 * argument.
*/
char	**multi_arrjoin_n_free(char *to_free, char **s1, ...)
{
	t_majnf	v;

	if (!s1)
		return (NULL);
	v = (t_majnf){0};
	if (to_free)
		v.tabs_to_free = str_to_arrint(to_free, &v.tab_len);
	va_start(v.args, s1);
	v.arg = va_arg(v.args, char **);
	if (!v.arg)
	{
		v.new_arr = ft_arrdup(s1);
		if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
			free_array(&s1);
		return (va_end(v.args), free(v.tabs_to_free), v.new_arr);
	}
	v.new_arr = ft_arrjoin(s1, v.arg);
	if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
		free_array(&s1);
	v.cur_str++;
	return (multi_arrjoin_n_free2(v));
}
