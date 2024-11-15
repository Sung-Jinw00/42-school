/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:12:14 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 23:12:52 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcslen(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j++])
				return (i);
		}
		i++;
	}
	return (i);
}

int	nb_sepable(char *str, char *charset)
{
	int	count;
	int	len_sepable;

	count = 0;
	while (*str)
	{
		len_sepable = ft_strcslen(str, charset);
		if (len_sepable)
		{
			str += len_sepable;
			count++;
		}
		if (*str)
			str++;
	}
	return (count);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*s;

	s = malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*src && i < n)
		s[i++] = *src++;
	s[i] = '\0';
	return (s);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		len_sepable;
	int		i;

	arr = malloc(sizeof(char *) * (nb_sepable(str, charset) + 1));
	i = 0;
	while (*str)
	{
		len_sepable = ft_strcslen(str, charset);
		if (len_sepable)
		{
			arr[i++] = ft_strndup(str, len_sepable);
			str += len_sepable;
		}
		if (*str)
			str++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split_once(char *str, char *charset)
{
	char	**arr;
	int		len_sepable;
	int		i;

	arr = malloc(sizeof(char *) * 3);
	if (!arr)
		return (NULL);
	i = 0;
	len_sepable = ft_strcslen(str, charset);
	arr[i++] = ft_strndup(str, len_sepable);
	str += len_sepable;
	if (*str)
		str++;
	arr[i++] = ft_strndup(str, ft_strcslen(str, ""));
	arr[i] = NULL;
	return (arr);
}
