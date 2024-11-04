/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:19:54 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 19:19:54 by marvin           ###   ########.fr       */
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
