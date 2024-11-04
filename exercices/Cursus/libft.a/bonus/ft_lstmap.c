/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:53:48 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 19:53:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*start_newlist;
	t_list	*temp;

	newlist = malloc(sizeof(t_list));
	if (!lst)
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
