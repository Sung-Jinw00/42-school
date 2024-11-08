/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:16 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:16 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_cmp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_trimage(char const *s1, char const *set, char *s1_cpy)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = ft_strlen(s1) - 1;
	while (set_cmp(s1[i], set))
		i++;
	while (set_cmp(s1[j], set))
		j--;
	while (i <= j)
		s1_cpy[k++] = ((char *)s1)[i++];
	s1_cpy[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_cpy;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (set_cmp(s1[i], set))
		i++;
	while (set_cmp(s1[j], set))
		j--;
	if (i >= j)
	{
		i = 0;
		j = 0;
	}
	s1_cpy = malloc(j - i + 2);
	if (!s1_cpy)
		return (NULL);
	ft_trimage(s1, set, s1_cpy);
	return (s1_cpy);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "   \t  \n\n \t\t  \n\n \t  \n \n	\n \n \t\t\n  ";
 	char *s2 = "";
 	char *ret = ft_strtrim(s1, " \n\t");
 
	printf("%s\n", ret);
 	if (!strcmp(ret, s2))
		printf("nickel");
	free(ret);
	return (0);
} */
