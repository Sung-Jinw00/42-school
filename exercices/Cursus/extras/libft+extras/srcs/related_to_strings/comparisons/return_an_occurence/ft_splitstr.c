/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:42 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 18:24:10 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * Search the first iteration of str in split
*/
char	**ft_split_strsrch(char **split, char *str)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!ft_strcmp(split[i], str))
			return ((char **)(split + i));
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	const char *s = NULL;

	s = ft_strchr(s, 'H');
	printf("%s\n", s);
	return (0);
} */
