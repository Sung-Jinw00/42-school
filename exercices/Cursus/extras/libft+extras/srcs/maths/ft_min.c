/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:29 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 14:39:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Find the lowest number of an array of ints.
 * 
 * @returns
 * The lowest number of an array of ints.*/
/**
 * - Else 404 if tab is NULL.
*/
int	ft_min(int *tab)
{
	int	i;
	int	min;

	if (!tab)
		return (404);
	i = 0;
	min = tab[0];
	while (tab[++i])
		if (tab[i] < min)
			min = tab[i];
	return (min);
}
