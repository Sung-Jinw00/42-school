/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/12 16:49:09 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* change the value of a cell of the list at the wished position */

void	set_at(t_list *L, void *data, int pos)
{
	int	i;

	i = 0;
	if (!L)
		return ((void)printf("liste vide\n"));
	else if (pos > len_list(L))
		return ((void)printf("position invalide\n"));
	while (++i < pos)
		L = L->next;
	L->data = data;
}
