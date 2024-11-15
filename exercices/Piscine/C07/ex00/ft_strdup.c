/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:54:48 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/15 14:08:48 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/* #include <stddef.h>
#include <stdio.h> */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len_src;
	int		i;

	i = 0;
	len_src = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!cpy)
		return (NULL);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/* int	main(void)
{
	char src[] = "Hello";
	char *cpy;
	
	cpy = ft_strdup(src);
	printf("adresse de src : %p\nsrc : %s\nadresse de cpy : %p\n
	cpy : %s\n", src, src, cpy, cpy);
	free (cpy);
	return (0);
} */