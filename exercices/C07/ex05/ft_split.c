/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:48:44 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/17 11:14:03 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_skip_charset(char s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_skip_charset(str[i], charset) == 0)
		i++;
	return (i);
}

int	ft_cnt_words(char *s1, char *s2)
{
	int	i;
	int	count;
	int	trigger;

	i = 0;
	count = 0;
	trigger = 0;
	while (s1 && s1[i])
	{
		if (ft_skip_charset(s1[i], s2) == 0 && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		if (ft_skip_charset(s1[i], s2) == 1 && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count);
}

char	**ft_write_words(char **split, char *str, char *charset, int i)
{
	int	j;
	int	k;
	int	len_word;

	k = -1;
	j = 0;
	while (ft_skip_charset(str[i], charset) == 1)
		i++;
	while (str[i] && ft_cnt_words(str, charset) != 0)
	{
		if (ft_strlen(str + i, charset) != 0
			&& ft_skip_charset(str[i], charset) == 0)
		{
			len_word = ft_strlen(str + i, charset);
			split[++k] = (char *)malloc(sizeof(char) * (len_word + 1));
			while (j < len_word)
				split[k][j++] = str[i++];
			split[k][j] = '\0';
		}
		j = 0;
		i++;
	}
	split[ft_cnt_words(str, charset)] = NULL;
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_cnt_words(str, charset) + 1));
	if (!split)
		return (NULL);
	split = ft_write_words(split, str, charset, i);
	return (split);
}

/* #include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *str = " J'adore le C07 ";
	char *charset = " \t'";
	char **split;
	int i = 0;
	
	split = ft_split(str, charset);
	if (split[i])
	{
		while (split[i - 1])
		{
			printf("chaque tableau de split : %s\n", split[i]);
			free(split[i]);
			i++;
		}
	}
	else
		printf("tableau vide : %s\n", split[0]);
	free(split);
	return (0);
} */