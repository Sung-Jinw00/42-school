/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/27 20:30:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* free a cell in the list at the position wished
*/
t_list	*free_at(t_list *L, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;

	cur = L;
	if (!L)
		return (NULL);
	else if (pos == 0)
	{
		L = L->next;
		free(cur);
		return (L);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (L);
}
