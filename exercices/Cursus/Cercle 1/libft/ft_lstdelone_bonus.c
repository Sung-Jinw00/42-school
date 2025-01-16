/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:46 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	del(void *content)
{
	free(content);
}  */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
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
	cell = ft_newcell(nb);
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
		if (*(int *)L->content >= 0 && *(int *)L->content <= 9)
			printf("%d ", *(int *)L->content);
		else
			printf("(null) ");
		L = L->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	lst = add_at(lst, 5, 0);
	lst = add_at(lst, 7, 0);
	lst = add_at(lst, 3, 0);
	lst = add_at(lst, 6, 0);
	lst = add_at(lst, 9, 0);
	lst = add_at(lst, 2, 0);
	print_list(lst);
	ft_lstdelone(lst, *del);
	print_list(lst);
	return (0);
}
 */