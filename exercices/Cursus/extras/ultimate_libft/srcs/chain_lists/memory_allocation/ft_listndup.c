/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Duplicates a chain list up to n cells of src.
 * 
 * @return
 * - If src is NULL, or if n is out of the lenght of src, the function returns
 * NULL.*/
/**
 * - Else, it returns the duplicate of src.
*/
t_list	*ft_listndup(t_list *src, int n)
{
	t_list	*cpy;
	t_list	*tmp;
	int		i;

	if (!src)
		return (NULL);
	else if (n > len_list(src) || n < 0)
		return (ft_write(2, "Listndup : n is out of the len of src\n"), NULL);
	tmp = src;
	i = 0;
	cpy = NULL;
	while (tmp && n-- > 0)
	{
		cpy = add_at(cpy, tmp->data, i++);
		tmp = tmp->next;
	}
	return (cpy);
}
