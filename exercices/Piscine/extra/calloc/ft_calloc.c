/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:18:34 by marvin            #+#    #+#             */
/*   Updated: 2024/10/19 12:18:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_calloc(int *tab, int size)
{
	int i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return(NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}