/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:57 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/* #include <stdio.h>

t_list	*add_at(t_list *L, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_list	*cell;
	int		*nb;

	nb = malloc(4);
	*nb = data;
	prec = NULL;
	cur = L;
	cell = ft_lstnew(nb);
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

void	print_list(t_list *L)
{
	if (!L)
		return ;
	while (L)
	{
		printf("%d ", *(int *)L->content);
		L = L->next;
	}
	printf("\n");
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
	lst = add_at(lst, 7, 1);
	lst = add_at(lst, 3, 2);
	lst = add_at(lst, 6, 3);
	lst = add_at(lst, 9, 4);
	lst = add_at(lst, 2, 5);
	print_list(lst);
	lst = ft_lstlast(lst);
	printf("%d\n", *(int *)lst->content);
	free_list(lst);
	return (0);
} */
