/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Returns a new string that begins at start, and ended at len, or the end of s.
 *  
 * @param s The string that will be copied.
 * @param start The starting point of the new string.
 * @param len The len the new string.
 * @param to_free If to_free = true, s will be freed.
 * 
 * @returns
 * - If start is greater than the lenght of s, or if s is NULL or empty, it
 * will returns an empty string.*/
/**
 * - Else, it will returns the new string.
*/
char	*ft_substr(char *s, unsigned int start, size_t len, bool to_free)
{
	int				i;
	char			*new_str;
	unsigned int	limit;

	if (start >= ft_strlen(s) || !s || !s[0])
	{
		if (to_free)
			free(s);
		return (ft_strdup(""));
	}
	limit = start + (unsigned int)len;
	if (limit > ft_strlen(s))
		len = ft_strlen(s) - start;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while ((size_t)start < limit && s[start])
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	if (to_free)
		free(s);
	return (new_str);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);


	printf("%s\n", ret);
	if (!strncmp(ret, "", 1))
	{
		free(ret);
		printf("nickel");
		return (0);
	}
	free(ret);
	return (0);
} */
