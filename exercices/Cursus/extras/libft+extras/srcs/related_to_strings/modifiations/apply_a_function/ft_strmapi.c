/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 20:55:06 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Apply a function on each character of a copy of s.
 * 
 * @param s the string that will be copied.
 * @param f the function that will be applied to the copy of s, the prototype
 * is : f(unsigned int, char).
 * 
 * @return
 * The new modified copy of s.
 * 
 * @note
 * The free of s is the responsibility of the user.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(ft_strlen(s) + 1);
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
