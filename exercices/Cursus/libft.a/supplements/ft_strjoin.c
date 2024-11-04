/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:24 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/30 20:54:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_string;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = malloc(len);
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}

/* int	main(void)
{
	int size = 3;
	char **strs = (char **)malloc(size * sizeof(char *));
	char sep[] = "/";
	char *conca;
	
	strs[0] = "j'adore";
	strs[1] = "le";
	strs[2] = "C07";
	conca = ft_strjoin(size, strs, sep);
	printf("%s\n", conca);
	free(conca);
	free(strs);
	return (0);
} */