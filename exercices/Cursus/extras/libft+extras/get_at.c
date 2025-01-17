/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 18:31:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* display a value at the wished position */

int	get_at(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (!L)
	{
		printf("liste vide\n");
		return (-1);
	}
	else if (pos > len_list(L))
	{
		printf("position invalide\n");
		return (-1);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}
