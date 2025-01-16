/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 19:23:11 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_at(t_list *L, int data, int pos)
{
	int	i;

	i = 0;
	if (!L)
	{
		printf("liste vide\n");
		return ;
	}
	else if (pos > len_list(L))
	{
		printf("position invalide\n");
		return ;
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	L->data = data;
}
