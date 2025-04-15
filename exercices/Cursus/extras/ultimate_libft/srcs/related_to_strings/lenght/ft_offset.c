/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:13:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 20:55:10 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * An integer that skip all the first iterations of charset in str.
*/
int	ft_offset(const char *str, char *charset)
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
