/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:26:39 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/21 10:47:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	int	k;
	int	len_wrd;

	j = 0;
	k = 0;
	len_wrd = 0;
	while (skip_charset(str[i], charset))
		i++;
	while (str[i])
	{
		len_wrd = len_word(str + i, charset);
		if (len_wrd != 0 && !skip_charset(str[i], charset))
		{
			split[j] = (char *)malloc(sizeof(char) * (len_wrd + 1));
			while (k < len_wrd)
				split[j][k++] = str[i++];
			j++;
			k = 0;
		}
		i++;
	}
	split[ft_cnt_words(str, charset)] = NULL;
	return (split);
}

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

/* #include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*str1;
	char	*charset1;
	char	*str2;
	char	*charset2;
	char	*str3;
	char	*charset3;
	char	**split;
	int		i;

	str1 = "   J'adore\tle C07   ";
	charset1 = " \t'";
	str2 = " '\t''   \t  ";
	charset2 = " \t'";
	str3 = " J'adore le C07 ";
	charset3 = "";
	i = 0;
	split = ft_split(str1, charset1);
	if (split[i])
	{
		while (split[i - 1])
		{
			printf("tableau %d de split1 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
	}
	else
		printf("tableau vide1 : %s\n", split[0]);
	free(split);
	printf("\n");
	i = 0;
	split = ft_split(str2, charset2);
	if (split[i])
	{
		while (split[i - 1])
		{
			printf("tableau %d de split2 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
	}
	else
		printf("tableau vide2 : %s\n", split[0]);
	free(split);
	printf("\n");
	i = 0;
	split = ft_split(str3, charset3);
	if (split[i])
	{
		while (split[i - 1])
		{
			printf("tableau %d de split3 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
	}
	else
		printf("tableau vide3 : %s\n", split[0]);
	free(split);
	return (0);
}
 */