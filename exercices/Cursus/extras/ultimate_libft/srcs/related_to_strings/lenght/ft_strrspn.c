/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:13:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/16 12:16:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * Return the span of characters of `charset` at the end of `str`.
*/
int	ft_strrspn(const char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	if (!str)
		return (0);
	count = 0;
	i = ft_strlen(str);
	while (str[--i])
	{
		j = -1;
		while (charset[++j])
		{
			if (str[i] == charset[j])
			{
				count++;
				break ;
			}
		}
		if (!charset[j])
			break ;
	}
	return (count);
}
