/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:24 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/15 14:06:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stddef.h>
#include <stdio.h>
#include <unistd.h> */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*write_conca(char *conca, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		conca = ft_strcpy(conca, strs[i]);
		if (i < size - 1)
			conca = ft_strcpy(conca, sep);
		i++;
	}
	return (conca);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_words;
	int		len_sep;
	int		i;
	char	*conca;

	i = 0;
	if (size == 0)
	{
		conca = (char *)malloc(sizeof(char));
		conca[0] = '\0';
		return (conca);
	}
	while (i < size)
	{
		len_words = len_words + ft_strlen(strs[i]);
		i++;
	}
	len_sep = ft_strlen(sep) * (size - 1);
	conca = (char *)malloc(sizeof(char) * (len_words + len_sep + 1));
	if (!conca)
		return (NULL);
	conca[0] = 0;
	return (write_conca(conca, strs, sep, size));
}

/* int	main(void)
{
	int size = 3;
	char **strs = (char **)malloc(size * sizeof(char *));
	char sep[] = "/";
	char *conca;
	
	strs[0] = "j'adore";
	strs[1] = "le";
	strs[2] = "C07";
	conca = ft_strjoin(size, strs, sep);
	printf("%s\n", conca);
	free(conca);
	free(strs);
	return (0);
} */