/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:25:57 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <bsd/string.h>*/

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_trunc;
	unsigned int	len_dest;

	i = 0;
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	len_trunc = ft_strlen(dest) + ft_strlen(src);
	len_dest = ft_strlen(dest);
	while (src[i] != '\0' && i < size - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_trunc);
}

/*int main(void)
{
	char dest1[100] = "Hello ";
	char dest2[100] = "Hello ";
	char src[] = "World";
	unsigned int size = 11;

	printf("%u\n", ft_strlcat(dest1, src, size));
	puts(dest1);
	printf("%zu\n", strlcat(dest2, src, size));
	puts(dest2);
	return (0);
}*/