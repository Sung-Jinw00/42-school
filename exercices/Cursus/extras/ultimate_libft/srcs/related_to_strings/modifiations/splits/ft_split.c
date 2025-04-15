/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

int	skip_charset(char i, char *charset)
{
	int	j;

	if (!charset)
		return (0);
	j = 0;
	while (charset[j])
	{
		if (i == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_cnt_words(char *str, char *charset)
{
	int	i;
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (!skip_charset(str[i], charset) && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		if (skip_charset(str[i], charset) && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count);
}

int	len_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !skip_charset(str[i], charset))
		i++;
	return (i);
}

char	**write_split(char *str, char **split, char *charset, int i)
{
	int	j;
	int	len_wrd;

	j = 0;
	len_wrd = 0;
	while (skip_charset(str[i], charset))
		i++;
	while (str && i < (int)ft_strlen(str))
	{
		len_wrd = len_word(str + i, charset);
		if (len_wrd != 0 && !skip_charset(str[i], charset))
		{
			split[j] = ft_strndup(str + i, len_wrd);
			if (!split[j])
				return (free_array(&split), NULL);
			j++;
			i += len_wrd;
		}
		i++;
	}
	split[ft_cnt_words(str, charset)] = NULL;
	return (split);
}

/**
 * @brief
 * Split a string into a array of strings.
 * 
 * @param str the string that will be splited.
 * @param charset the string that contains the arguments that will be used as
 * separators to split str.
 * 
 * @return
 * The new array of strings.
 * 
 * @note
 * The free of str and charset is the responsibility of the user.
*/
char	**ft_split(char *str, char *charset)
{
	char	**split;

	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_cnt_words(str, charset) + 1));
	if (!split)
		return (NULL);
	return (write_split(str, split, charset, 0));
}
