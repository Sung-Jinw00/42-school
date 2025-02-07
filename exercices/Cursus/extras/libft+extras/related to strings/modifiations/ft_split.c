/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 17:54:45 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* split a string into a chain of strings depending on a character */

static int	ft_cnt_words(const char *str, char charset)
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

static int	len_word(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static char	**ft_free(char **split, int j)
{
	while (j >= 0)
		free(split[j--]);
	free(split);
	return (NULL);
}

static char	**write_split(const char *str, char **split, char charset, int i)
{
	int	j;
	int	len_wrd;

	j = 0;
	len_wrd = 0;
	while (str[i])
	{
		len_wrd = len_word(str + i, charset);
		if (len_wrd > 0 && str[i] != charset)
		{
			split[j] = ft_substr(str, i, len_wrd);
			if (!split[j])
				return (ft_free(split, j));
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

int	main(void)
{
	const char *str = malloc(0);
	str = 0;
	char **split = ft_split(str, 0);
	int i = 0;

	if (!split)
		printf("tableau null\n");
	else if (!split[0])
		printf("tableau vide : %s\n", split[0]);
	else if (split[i])
	{
		while (split[i])
		{
			printf("tableau %d de split1 : %s\n", i, split[i]);
			free(split[i]);
			i++;
		}
		printf("tableau %d de split1 : %s\n", i, split[i]);
	}
	free(split);
} */

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