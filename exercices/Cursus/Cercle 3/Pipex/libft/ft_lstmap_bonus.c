/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:02 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/31 18:33:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	t_list	*newlist;
	t_list	*start_newlist;
	t_list	*temp;

	*(int *)content += 5;
	return (content);
} */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *start_newlist;
	t_list *temp;

	newlist = malloc(sizeof(t_list));
	if (!lst || !newlist)
		return (NULL);
	temp = lst;
	newlist->content = (*f)(temp->content);
	newlist->next = NULL;
	start_newlist = newlist;
	while (temp->next)
	{
		newlist->next = malloc(sizeof(t_list));
		newlist = newlist->next;
		if (!newlist)
		{
			ft_lstclear(&start_newlist, del);
			return (NULL);
		}
		temp = temp->next;
		newlist->content = (*f)(temp->content);
		newlist->next = NULL;
	}
	return (start_newlist);
}

/* #include <stdio.h>

t_list	*ft_newcell(void *content)
{
	t_list	*newcell;

	newcell = malloc(sizeof(t_list));
	newcell->content = malloc(sizeof(int *));
	newcell->content = content;
	newcell->next = NULL;
	return (newcell);
}

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

int	main(void)
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
	ft_lstmap(lst, &f, &del);
	print_list(lst);
	return (0);
} */
