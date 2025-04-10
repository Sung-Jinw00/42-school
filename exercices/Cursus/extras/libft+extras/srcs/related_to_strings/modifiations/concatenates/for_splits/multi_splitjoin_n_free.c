/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_splitjoin_n_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:07:25 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 01:04:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

static bool	correct_format(char *str_char)
{
	int	i;

	i = 0;
	while (str_char[i])
	{
		if (ft_isnum(str_char[i]) || str_char[i] == '-' || str_char[i] == '+')
			i++;
		else if (ft_strcmp (str_char + i, ", ") && i != 0)
			i += 2;
		else
			return (0);
	}
	return (1);
}

int	has_to_be_freed(t_msjnf v, int *tab_inc)
{
	while (v.tabs_to_free[*tab_inc] < v.cur_str && *tab_inc < v.tab_len - 1)
		(*tab_inc)++;
	if (*tab_inc == v.tab_len - 1 && v.tabs_to_free[*tab_inc] < v.cur_str)
		return (0);
	if (v.tabs_to_free[*tab_inc] == v.cur_str)
		return (1);
	return (0);
}

char	**multi_spitjoin_n_free2(t_msjnf v)
{
	if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
		free_dbl_tab(&v.arg);
	if (!v.new_split)
		return (ft_putstr_fd(2, "fail join\n"), NULL);
	v.arg = va_arg(v.args, char **);
	v.cur_str = 2;
	while (v.arg)
	{
		v.new_split = ft_splitjoin_n_free(v.new_split, v.arg, 1);
		if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
			free_dbl_tab(&v.arg);
		if (!v.new_split)
			return (ft_putstr_fd(2, "fail join and free\n"), NULL);
		v.arg = va_arg(v.args, char **);
		v.cur_str++;
	}
	va_end(v.args);
	free(v.tabs_to_free);
	return (v.new_split);
}

/**
 * @brief
 * Join an infinite amount of array of strings and free the wished tabs.
 * 
 * @param to_free The string "to_free" follows the rules of the function
 * strchar_to_strint : */
/**
 * - Each numbers represent the position of each string that should be freed,
 * starting at position zero, if the number exceeds the limits of the amount
 * of strings, they will be ignored. */
/**
 * - The string must follow the format : "n1, n2, ..., nn". 
 * 
 * @note
 * - Every end of array of strings and the last argument should be NULL to
 * interrupt the function correctly, otherwise, undefined outcome may
 * happened.*/
/**
 * - If the format of to_free isn't respected, or if the string is NULL or
 * empty, the string will be considered NULL and no string will be freed.
 * 
 * @returns
 * The new joined array of strings, or the duplicate of s1 if there's no other
 * argument.
*/
char	**multi_splitjoin_n_free(char *to_free, char **s1, ...)
{
	t_msjnf	v;

	if (!s1)
		return (NULL);
	v = (t_msjnf){0};
	if (to_free && correct_format(to_free))
	{
		v.tabs_to_free = strchar_to_strint(to_free);
		v.tab_len = ft_strintlen(to_free);
	}
	va_start(v.args, s1);
	v.arg = va_arg(v.args, char **);
	if (!v.arg)
	{
		v.new_split = ft_splitdup(s1);
		if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
			free_dbl_tab(&s1);
		return (va_end(v.args), free(v.tabs_to_free), v.new_split);
	}
	v.new_split = ft_splitjoin(s1, v.arg);
	if (v.tabs_to_free && has_to_be_freed(v, &v.tab_increment))
		free_dbl_tab(&s1);
	v.cur_str++;
	return (multi_spitjoin_n_free2(v));
}
