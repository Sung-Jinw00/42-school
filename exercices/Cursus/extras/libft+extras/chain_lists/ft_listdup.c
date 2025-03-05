/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/26 18:47:09 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* duplicate a list */

t_list	*ft_listdup(t_list *src)
{
	t_list	*cpy;
	t_list	*tmp;
	int		i;

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

/* int	main(void)
{
	t_list	*src;
	t_list	*dup;
	
	src = NULL;
	src = add_at(src, "330", 0);
	src = add_at(src, "2527", 1);
	src = add_at(src, "7504", 2);
	src = add_at(src, "75042", 3);
	dup = ft_listdup(src);
	print_list(src);
	print_list(dup);
	free_list(src);
	free_list(dup);
	return (0);
} */
