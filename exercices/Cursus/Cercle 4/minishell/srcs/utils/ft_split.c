/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/06 23:54:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	skip_charset(char i, char *charset)
{
	int	j;

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
	while (str[i])
	{
		len_wrd = len_word(str + i, charset);
		if (len_wrd != 0 && !skip_charset(str[i], charset))
		{
			split[j] = ft_substr(str, i, len_wrd);
			if (!split[j])
				return (free_dbl_tab(split, j));
			i += len_wrd;
			if (str[i] == '\0')
				break ;
			j++;
		}
		i++;
	}
	split[ft_cnt_words(str, charset)] = NULL;
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;

	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_cnt_words(str, charset) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (!skip_charset(str[i], charset))
		i++;
	return (write_split(str, split, charset, 0));
}
