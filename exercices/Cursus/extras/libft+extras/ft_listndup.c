/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/17 21:54:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* duplicate a list on n cells of the list */

t_list	*ft_listndup(t_list *src, int n)
{
	t_list	*cpy;
	t_list	*tmp;
	int		i;

	tmp = src;
	i = 0;
	cpy = NULL;
	while (tmp && n-- > 0)
	{
		cpy = add_at(cpy, tmp->data, i);
		i++;
		tmp = tmp->next;
	}
	return (cpy);
}
