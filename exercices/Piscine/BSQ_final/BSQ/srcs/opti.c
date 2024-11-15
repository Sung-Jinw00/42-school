/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:03:15 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/25 12:28:44 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*write_conca(char *conca, char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		conca = ft_strcpy(conca, strs[i]);
		i++;
	}
	return (conca);
}

char	*ft_strjoin(char **strs)
{
	int		len_words;
	int		i;
	char	*conca;

	i = 0;
	while (strs[i])
	{
		len_words = len_words + ft_strlen(strs[i]);
		i++;
	}
	conca = (char *)malloc(sizeof(char) * (len_words + 1));
	if (!conca)
		return (NULL);
	conca[0] = 0;
	return (write_conca(conca, strs, i - 1));
}
