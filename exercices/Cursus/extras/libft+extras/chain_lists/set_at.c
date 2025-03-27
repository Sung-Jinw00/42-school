/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/27 20:28:05 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* change the value of a cell of the list at the wished position
*/
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
