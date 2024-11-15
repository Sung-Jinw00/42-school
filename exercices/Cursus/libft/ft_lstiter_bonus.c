/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:52 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:52 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>

void	f(void *content)
{
	*(int *)content += 5;
} */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;

	if (!lst)
		return ;
	cur = lst;
	while (cur)
	{
		(*f)(cur->content);
		cur = cur->next;
	}
}

/* t_list	*add_at(t_list *L, int data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;
	t_list	*cell;
	int *nb;

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

void	free_list(t_list *L)
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

int main(void)
{
	t_list *lst;

	lst = NULL;
	lst = add_at(lst, 5, 0);
	lst = add_at(lst, 7, 0);
	lst = add_at(lst, 3, 0);
	lst = add_at(lst, 6, 0);
	lst = add_at(lst, 9, 0);
	lst = add_at(lst, 2, 0);
	print_list(lst);
	ft_lstiter(lst, *f);
	print_list(lst);
	free_list(lst);
	return (0);
} */
