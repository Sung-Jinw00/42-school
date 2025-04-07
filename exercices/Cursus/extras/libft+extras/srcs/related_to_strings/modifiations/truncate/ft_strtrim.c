/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:16 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 01:07:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

static int	set_cmp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief
 * Remove the characters found in "set" at start and end of s1.
 * 
 * @param s1 The string that will be trimmed.
 * @param set The string of characters that will be removed from the extremities
 * of s1.
 * @param to_bree If to_free = true, s1 will be freed, else, it won't.
 * 
 * @return
 * The new string trimmed.
*/
char	*ft_strtrim(char const *s1, char const *set, bool to_free)
{
	int	i;
	int	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (set_cmp(s1[i], set))
		i++;
	if (i == j)
		return (ft_strdup(""));
	j--;
	while (set_cmp(s1[j], set) && j > i)
		j--;
	return (ft_substr((char *)s1, i, j - i + 1, to_free));
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = "   \t  \n\n \t\t  \n\n \t  \n \n	\n \n \t\t\n  ";
	char *s2 = "";
	char *ret = ft_strtrim(s1, " \n\t");

	printf("%s\n", ret);
	if (!strcmp(ret, s2))
		printf("nickel");
	free(ret);
	return (0);
} */
