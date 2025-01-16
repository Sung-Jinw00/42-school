/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 19:10:19 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listdup(t_list *src)
{
	t_list *cpy;
	t_list *tmp;
	int i;

	tmp = src;
	i = 0;
	cpy = NULL;
	while (tmp)
	{
		cpy = add_at(cpy, tmp->data, i);
		i++;
		tmp = tmp->next;
	}
	return (cpy);
}