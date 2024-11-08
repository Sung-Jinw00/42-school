/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:37 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/08 15:03:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cnt_words(const char *str, char charset)
{
	int	i;
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != charset && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		if (str[i] == charset && trigger == 1)
			trigger = 0;
		i++;
	}
	return (count);
}

int	len_word(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

char	**free_split(char **split, int j)
{
	while (j >= 0)
		free(split[j--]);
	free(split);
	return (NULL);
}

char	**write_split(const char *str, char **split, char charset, int i)
{
	int	j;
	int	k;
	int	len_wrd;

	j = 0;
	k = 0;
	len_wrd = 0;
	while (str[i])
	{
		len_wrd = len_word(str + i, charset);
		if (len_wrd > 0 && str[i] != charset)
		{
			split[j] = malloc(sizeof(char) * (len_wrd + 1));
			if (!split[j])
				return (free_split(split, j));
			while (k < len_wrd)
				split[j][k++] = str[i++];
			split[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	split[ft_cnt_words(str, charset)] = NULL;
	return (split);
}

char	**ft_split(char const *str, char charset)
{
	char	**split;
	int		i;

	if (!str)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_cnt_words(str, charset) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (str[i] == charset)
		i++;
	return (write_split(str, split, charset, i));
}

/* #include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *str1 = "   J'adore le C07   ";
	char charset1 = ' ';

	char *str2 = "              ";
	char charset2 = ' ';
	
	char *str3 = " J'adore le C07 ";
	char charset3 = 0;
	
	char **split;
	int i = 0;
	
	split = ft_split(str1, charset1);
	if (split[i])
	{
		while (split[i])
		{
			printf("tableau %d de split1 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
		printf("tableau %d de split1 : %s\n", i, split[i]);
	}
	else
		printf("tableau vide1 : %s\n", split[0]);
	free(split);
	printf("\n");
	i = 0;
	split = ft_split(str2, charset2);
	if (split[i])
	{
		while (split[i])
		{
			printf("tableau %d de split2 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
		printf("tableau %d de split2 : %s\n", i, split[i]);
	}
	else
		printf("tableau vide2 : %s\n", split[0]);
	free(split);
	printf("\n");
	i = 0;
	split = ft_split(str3, charset3);
	if (split[i])
	{
		while (split[i])
		{
			printf("tableau %d de split3 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
		printf("tableau %d de split3 : %s\n", i, split[i]);
	}
	else
		printf("tableau vide3 : %s\n", split[0]);
	free(split);
	return (0);
} */