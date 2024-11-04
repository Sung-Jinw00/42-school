/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:07 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:35:07 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newcell;

	newcell = malloc(sizeof(t_list));
	newcell->content = content;
	newcell->next = NULL;
	return (newcell);
}

/* #include <stdio.h>

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

int main(void)
{
	char *c = "bonus";
	void *content = c;
	t_list *newcell = ft_lstnew(content);

	printf("%s\n", (char *)newcell->content);
	printf("%s\n", (char *)newcell->next);
	free_list(newcell);
	return (0);
} */
