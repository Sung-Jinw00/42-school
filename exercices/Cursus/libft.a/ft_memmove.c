/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:20:55 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 16:20:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*cpy;

	i = 0;
	if (!dest || !src)
		return (0);
	if (dest > src)
	{
		while (n-- > 0)
			*(char *)(dest + n) == *(char *)(src + n);
	}
	else
	{
		while (i < n)
		{
			*(char *)(dest + i) == *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
