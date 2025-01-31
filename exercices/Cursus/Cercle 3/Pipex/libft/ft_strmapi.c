/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/31 18:31:35 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char f(unsigned int i, char s)
{
	char			*cpy;
	unsigned int	i;

	if (s >= 'A' && s <= 'Z')
		return (s += 32);
	else if (s >= 'a' && s <= 'z')
		return (s -= 32);
	else
		i = 1;
	if (i == 1)
		return (s);
	return (s);
} */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i = 0;
	char *cpy = malloc(ft_strlen(s) + 1);
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/* #include <stdio.h>

int	main(void)
{
	char *s = "Hello World";

	s = ft_strmapi((const char *)s, *f);
	printf("%s\n", s);
	free(s);
	return (0);
} */
