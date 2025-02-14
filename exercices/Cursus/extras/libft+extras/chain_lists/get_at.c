/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/12 16:47:32 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* display a value at the wished position */

void	*get_at(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (!L)
		return (printf("liste vide\n"), NULL);
	else if (pos > len_list(L))
		return (printf("position invalide\n"), NULL);
	while (++i < pos)
		L = L->next;
	return (L->data);
}
