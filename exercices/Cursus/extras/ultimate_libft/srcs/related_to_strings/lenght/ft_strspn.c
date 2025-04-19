/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:13:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/16 12:10:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * Return the span of characters of `charset` at start of `str`.
*/
int	ft_strspn(const char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
			{
				i++;
				break ;
			}
		}
		if (!charset[j])
			break ;
	}
	return (i);
}
