/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roffset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:13:33 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/16 12:17:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * Return the span of `c` at end of `str`.
*/
int	ft_roffset(const char *str, char c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = ft_strlen(str);
	count = 0;
	while (--i >= 0 && str[i] == c)
		count++;
	return (count);
}
