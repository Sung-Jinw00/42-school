/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:14:12 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/11 13:44:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		j = 0;
		i++;
	}
	return (0);
}

/*int main(void)
{
	char str[] = "Hello World, wassup ?";
	char to_find[] = "World";

	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}*/