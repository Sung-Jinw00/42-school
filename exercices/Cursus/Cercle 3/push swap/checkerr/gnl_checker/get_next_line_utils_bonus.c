/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:56 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/28 17:48:56 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_string;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len = ft_strclen(s1, '\0') + ft_strclen(s2, '\0') + 1;
	new_string = (char *)ft_calloc(len, 1);
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	free(s1);
	return (new_string);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}
