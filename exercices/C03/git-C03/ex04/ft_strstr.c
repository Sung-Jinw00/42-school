/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:14:12 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/09 16:29:47 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_strcmp(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] != to_find[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_strcmp(str, to_find, i) == 1)
				return (str + i);
		}
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