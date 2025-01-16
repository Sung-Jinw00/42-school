/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:47:03 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/19 21:46:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *str, size_t n)
{
	char	*cpy;
	size_t	i;

	i = -1;
	cpy = malloc(n + 1);
	if (!cpy)
		return (NULL);
	while (++i < n)
		cpy[i] = str[i];
	cpy[n] = '\0';
	return (cpy);
}
