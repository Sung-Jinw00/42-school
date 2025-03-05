/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/28 20:10:33 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* create a dublicate of a splited string at start tab up to end tab */

char	**ft_splitndup(char **split, int len_split, int start, int end)
{
	char	**dup;
	int		i;
	
	if (end > len_split)
		end = len_split;
	if (start > end || !split)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (start < end)
	{
		dup[i++] = ft_strdup(split[start++]);
		if (!dup[i - 1])
			return (free_dbl_tab(dup), NULL);
	}
	dup[i] = NULL;
	return (dup);
}

/* #include <stdio.h>

int	main(void)
{
	char src[] = "Hello";
	char *cpy;

	cpy = ft_strdup(src);
	printf("adresse de src : %p\nsrc : %s\nadresse de cpy : %p\ncpy : %s\n",\
	src, src, cpy, cpy);
	free (cpy);
	return (0);
} */