/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:24:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Creates an array of ints between `min` and `max` (both included) and give
 * the len of the array through the pointer of len_array.
 * 
 * @param min The minimal number at the start of the array.
 * @param max The maximal number at the end of the array.
 * @param len_array The pointer that will receive the array's len.
 * 
 * 
 * @returns
 * - If `min >= max`, the function will set len_array to zero and return NULL.*/
/**
 * - Else, the function will return an array of ints between `min` and `max`
 * (both included), and len will receive the lenght of the array.
*/
int	*ft_range(int min, int max, int *len_array)
{
	int	i;
	int	*array;

	i = 0;
	if (min >= max)
		return (*len_array = 0, NULL);
	*len_array = max - min + 1;
	array = (int *)malloc(sizeof(int) * *len_array);
	if (!array)
		return (*len_array = 0, NULL);
	while (min <= max)
		array[i++] = min++;
	return (array);
}
