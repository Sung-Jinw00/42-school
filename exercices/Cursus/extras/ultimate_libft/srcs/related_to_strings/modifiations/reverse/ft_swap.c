/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:48:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/14 12:48:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Swap 2 datas.
 * 
 * @param elem1 The pointer on the first data.
 * @param elem2 The pointer on the second data.
 * @param size The sizeof the data to swap.
 * 
*/
void	ft_swap(void *elem1, void *elem2, size_t size)
{
	unsigned char	tmp;
	size_t			i;

	if (!elem1 || !elem2 || size == 0)
		return ;
	i = -1;
	while (++i < size)
	{
		tmp = ((unsigned char *)elem1)[i];
		((unsigned char *)elem1)[i] = ((unsigned char *)elem2)[i];
		((unsigned char *)elem2)[i] = tmp;
	}
}
