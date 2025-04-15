/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Duplicates a string.
 * 
 * @returns
 * - If src is NULL, the function returns NULL.*/
/**
 * - Else, the function will return the duplicate string.
*/
char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		len_src;
	int		i;

	if (!src)
		return (NULL);
	len_src = (int)ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!cpy)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		cpy[i] = src[i];
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