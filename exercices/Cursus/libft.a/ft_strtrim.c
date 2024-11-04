/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:16 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:16 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_cmp(char c, const char *set)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_cpy;
	int		count_set;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count_set = 0;
	while (s1[i] != '\0')
	{
		if (set_cmp(s1[i], set))
			count_set++;
		i++;
	}
	s1_cpy = malloc((int)ft_strlen(s1) + 1 - count_set);
	i = 0;
	while (s1[i] != 0)
	{
		if (!set_cmp(s1[i], set))
			s1_cpy[j++] = s1[i++];
		while (set_cmp(s1[i], set) && s1[i] != 0)
			i++;
	}
	return (s1_cpy);
}

/* #include <stdio.h>

int main(void)
{
	const char *s1 = "Hello world";
	const char *set = "o";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
} */
