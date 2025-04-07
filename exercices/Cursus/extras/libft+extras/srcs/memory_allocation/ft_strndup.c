/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:31:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Duplicates n bytes of a string.
 * 
 * @returns
 * - If src is NULL, the function returns NULL.*/
/**
 * - Else, the function will return the duplicate of n bytes of src.
*/
char	*ft_strndup(const char *src, int n)
{
	char	*cpy;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	if (n > (int)ft_strlen(src))
		n = (int)ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (!cpy)
		return (NULL);
	while (src[i] && i < n)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
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