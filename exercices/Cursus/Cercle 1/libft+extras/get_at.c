/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_list copy 2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 19:23:34 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
