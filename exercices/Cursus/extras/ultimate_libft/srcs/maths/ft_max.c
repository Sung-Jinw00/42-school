/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:29 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Find the highest number of an array of ints.
 * 
 * @returns
 * The highest number of an array of ints.*/
/**
 * - Else 404 if tab is NULL.
*/
int	ft_max(int *tab)
{
	int	i;
	int	max;

	if (!tab)
		return (404);
	max = tab[0];
	i = 0;
	while (tab[++i])
		if (tab[i] > max)
			max = tab[i];
	return (max);
}
