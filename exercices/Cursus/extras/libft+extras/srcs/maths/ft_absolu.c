/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:29 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/09 01:05:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

void	nb_cpy(void *nb, void *dup, char *type)
{
	if (!ft_strcmp(type, TYPE_INT))
		*(int *)dup = -(*(int *)nb);
	else if (!ft_strcmp(type, TYPE_LONG))
		*(long *)dup = -(*(long *)nb);
	else if (!ft_strcmp(type, TYPE_LLONG))
		*(long long *)dup = -(*(long long *)nb);
	else if (!ft_strcmp(type, TYPE_INT64))
		*(int64_t *)dup = -(*(int64_t *)nb);
	else if (!ft_strcmp(type, TYPE_DOUBLE))
		*(double *)dup = -(*(double *)nb);
	else if (!ft_strcmp(type, TYPE_FLOAT))
		*(float *)dup = -(*(float *)nb);
	else
		*(int *)dup = 0;
}

/**
 * @brief
 * Find the absolute value of any non-unsigned value, and assign it to another
 * value via her pointer.
 * 
 * @param nb The pointer to the value that will enter in the function.
 * @param dup The pointer to the value that will be the absolute value of nb.
 * @param type A string that specify the non-unsigned type of nb, it can be
 * "int", "long" , "long long", "double", "int64"or "float".
 * 
 * If the type isn't find, the value of dup will be 0.
*/
void	ft_absolu(void *nb, void *dup, char *type)
{
	if (!dup)
		return ;
	if (!nb || !type)
	{
		*(int *)dup = 0;
		return ;
	}
	if (!ft_strcmp(type, TYPE_INT) && *(int *)nb < 0)
		*(int *)dup = -(*(int *)nb);
	else if (!ft_strcmp(type, TYPE_LONG) && *(long *)nb < 0)
		*(long *)dup = -(*(long *)nb);
	else if (!ft_strcmp(type, TYPE_LLONG) && *(long long *)nb < 0)
		*(long long *)dup = -(*(long long *)nb);
	else if (!ft_strcmp(type, TYPE_INT64) && *(int64_t *)nb < 0)
		*(int64_t *)dup = -(*(int64_t *)nb);
	else if (!ft_strcmp(type, TYPE_DOUBLE) && *(double *)nb < 0)
		*(double *)dup = -(*(double *)nb);
	else if (!ft_strcmp(type, TYPE_FLOAT) && *(float *)nb < 0)
		*(float *)dup = -(*(float *)nb);
	else
		nb_cpy(nb, dup, type);
}
