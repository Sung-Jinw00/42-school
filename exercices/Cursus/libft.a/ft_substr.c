/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:21 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:21 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*new_str;
	unsigned int	max_len;

	new_str = malloc(len + 1);
	max_len = start + (unsigned int)len;
	i = 0;
	while (start < max_len && s[start])
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}

/* #include <stdio.h>

int main(void)
{
	char const *s = "Hello world";
	unsigned int start = 0;

	printf("%s\n", ft_substr(s, start, 5));
	return (0);
} */
