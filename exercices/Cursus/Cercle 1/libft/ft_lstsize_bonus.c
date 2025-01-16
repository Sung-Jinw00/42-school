/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:35:11 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	cur = lst;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

/* #include <stdio.h>

t_list	*add_at(t_list *L, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_list	*cell;

	cur = L;
	cell = ft_lstnew((void *)&data);
	if (!L)
		return (cell);
	else if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (L);
}

t_list	*free_list(t_list *L)
{
	t_list	*tmp;

	tmp = NULL;
	while (L)
	{
		tmp = L->next;
		free (L);
		L = tmp;
	}
}

int	main(void)
{
	t_list *lst;

	lst = NULL;
	lst = add_at(lst, 5, 0);
	printf("%d\n", ft_lstsize(lst));
	free_list(lst);
	return (0);
} */
