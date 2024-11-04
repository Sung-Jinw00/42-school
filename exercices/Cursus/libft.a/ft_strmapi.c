/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:05 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:05 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char f(unsigned int i, char s)
{
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
	char			*cpy;
	unsigned int	i;

	i = 0;
	cpy = malloc((int)ft_strlen(s));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = (*f)(i, s[i]);
		i++;
	}
	return (cpy);
}

/* #include <stdio.h>

int main(void)
{
	const char *s = "Hello World";

	printf("%s\n", ft_strmapi(s, *f));
	return (0);
} */
