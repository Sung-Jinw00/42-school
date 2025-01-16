/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:04:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 17:04:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
/* #include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(void *s1, void *s2)
{
	char	*a;
	char	*b;
	int		i;

	i = -1;
	a = (char *)s1;
	b = (char *)s2;
	while (a[++i] || b[i])
		if (a[i] != b[i])
			return (a[i] - b[i]);
	return (0);
}

void	free_fct(void *data)
{
	t_list	*temp;

	free(data);
} */
void	ft_list_remove_if2(t_list **cur, t_list **prev, void *data_ref,
		int (*cmp)())
{
	temp = NULL;
	while (*cur)
	{
		if ((*cmp)((*cur)->data, data_ref) == 0)
		{
			temp = *cur;
			*cur = (*cur)->next;
			(*prev)->next = *cur;
			free_fct(temp->data);
			free(temp);
		}
		else
			*cur = (*prev)->next;
		*prev = *cur;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*prev;

	prev = *begin_list;
	while ((*cmp)(prev->data, data_ref) == 0)
	{
		cur = prev->next;
		free_fct(prev->data);
		free(prev);
		prev = cur;
	}
	cur = prev->next;
	ft_list_remove_if2(&cur, &prev, data_ref, cmp);
}

/* void	print_list(t_list *L)
{
	while (L)
	{
		printf("%s ", (char *)L->data);
		L = L->next;
	}
	printf("\n");
}

t_list	*add_at(t_list *L, void *data, int pos)
{
	t_list	*prec;
	t_list	*cur;
	t_list	*cell;
	int		i;

	i = 0;
	cur = L;
	cell = ft_create_elem(data);
	if (!L)
		return (cell);
	else if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
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

int main (void)
{
	t_list *newlist;
	void *ref;
	char *yes = "yeah";
	ref = yes;
	char *data1;
	char *data2;
	char *data3;

	newlist = NULL;
	data1 = strdup("oh");
	newlist = add_at(newlist, data1, 0);
	data2 = strdup("yeah");
	newlist = add_at(newlist, data2, 1);
	data3 = strdup("more...");
	newlist = add_at(newlist, data3, 2);
	printf("liste : ");
	print_list(newlist);
	printf("data de reference : %s\n", yes);
	ft_list_remove_if(&newlist, ref, *ft_strcmp, *free_fct);
	printf("nouvelle liste : ");
	print_list(newlist);
} */
