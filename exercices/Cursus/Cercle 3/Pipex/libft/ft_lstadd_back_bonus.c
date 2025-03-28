/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:31 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:31 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
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

int	main(void)
{
	t_list	*lst;
	int		*nb;

	lst = NULL;
	lst = add_at(lst, 5, 0);
	lst = add_at(lst, 7, 0);
	lst = add_at(lst, 3, 0);
	lst = add_at(lst, 6, 0);
	lst = add_at(lst, 9, 0);
	lst = add_at(lst, 2, 0);
	print_list(lst);
	nb = malloc(4);
	*nb = 13;
	ft_lstadd_back(&lst, ft_lstnew(nb));
	print_list(lst);
	free_list(lst);
	free(nb);
	return (0);
}
 */

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list *l = ((void*)0);
	t_list *n = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
	{
		free(l->next);
		free(l);
		printf("gg mec");
		return (0);
	}
	free(l->next);
	free(l);
	return (0);
} */