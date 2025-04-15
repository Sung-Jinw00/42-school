/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

int	ft_cnt_words(char *str, char *sep)
{
	size_t	i;
	size_t	len_sep;
	int		trigger;
	int		count;

	trigger = 0;
	count = 0;
	i = 0;
	len_sep = ft_strlen(sep);
	while (i < ft_strlen(str) && str[i])
	{
		if (!ft_strncmp(str + i, sep, len_sep) && trigger == 0)
		{
			trigger = 1;
			count++;
			i += len_sep - 1;
		}
		else if (!ft_strncmp(str + i, sep, len_sep) && trigger == 1)
			i += len_sep - 1;
		if (ft_strncmp(str + i, sep, len_sep) && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count);
}

char	**write_split(char *str, char **split, char *sep, size_t i)
{
	int	j;
	int	len_wrd;
	int	len_sep;

	j = 0;
	len_wrd = 0;
	len_sep = ft_strlen(sep);
	while (i < ft_strlen(str) && !ft_strncmp(str + i, sep, len_sep))
		i += len_sep;
	while (i < ft_strlen(str) && str)
	{
		len_wrd = ft_str_strlen(str + i, sep);
		if (len_wrd != 0 && ft_strncmp(str + i, sep, len_sep))
		{
			split[j] = ft_strndup(str + i, len_wrd);
			if (!split[j++])
				return (free_array(&split), NULL);
			i += len_wrd;
		}
		else if (!ft_strncmp(str + i, sep, len_sep))
			i += len_sep - 1;
		i++;
	}
	split[ft_cnt_words(str, sep)] = NULL;
	return (split);
}

/**
 * @brief
 * Split a string into a array of strings.
 * 
 * @param str the string that will be splited.
 * @param sep the string that will be used as a separator to split str.
 * 
 * @return
 * The new array of strings.
 * 
 * @note
 * The free of str and sep is the responsibility of the user.
*/
char	**ft_strsplit(char *str, char *sep)
{
	char	**split;

	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_cnt_words(str, sep) + 1));
	if (!split)
		return (NULL);
	return (write_split(str, split, sep, 0));
}
