/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:49:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 12:49:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

int ft_strcmp(int s1, int s2)
{
    return (s1 - s2);
}

void    ft_list_remove_if(t_list **begin_list, int data_ref, int (*cmp)())
{
    t_list *temp;
    t_list *prev;
    t_list *next;

    while (*begin_list)
    {
        prev = *begin_list;
        temp = (*begin_list)->next;
        if (temp)
        {
            if (!cmp(temp->data, data_ref))
            {
                next = (*begin_list)->next;
                prev->next = next;
                free (*begin_list);
            }
        }
        *begin_list = (*begin_list)->next;
    }
}