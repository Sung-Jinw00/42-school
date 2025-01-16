/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 19:15:31 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	len_list(t_list *L)
{
	long	len;

	len = 0;
	while (L)
	{
		len++;
		L = L->next;
	}
	return (len);
}
int	is_empty_list(t_list *L)
{
	return (L == NULL);
}

t_cell	*create_cell(int data)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
}

void	print_list(t_list *L)
{
	while (L)
	{
		printf("%d ", L->data);
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
		free(L);
		L = tmp;
	}
}

t_list	*free_at(t_list *L, int pos)
{
	t_list	*prec;
	t_list	*cur;
	int		i;

	cur = L;
	if (!L)
		return (NULL);
	else if (pos == 0)
	{
		L = L->next;
		free(cur);
		return (L);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (L);
}

void	set_at(t_list *L, int data, int pos)
{
	int	i;

	i = 0;
	if (!L)
	{
		printf("liste vide\n");
		return ;
	}
	else if (pos > len_list(L))
	{
		printf("position invalide\n");
		return ;
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	L->data = data;
}

int	get_at(t_list *L, int pos)
{
	int	i;

	i = 0;
	if (!L)
	{
		printf("liste vide\n");
		return (-1);
	}
	else if (pos > len_list(L))
	{
		printf("position invalide\n");
		return (-1);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}

t_list	*add_at(t_list *L, int data, int pos)
{
	t_list *prec;
	t_list *cur;
	int i;
	t_cell *cell;

	cur = L;
	cell = create_cell(data);
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