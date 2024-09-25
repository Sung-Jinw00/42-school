/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:49:35 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/19 18:12:48 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof (t_list) * 1);
	elem[0].data = data;
	elem[0].next = 0;
	printf("data : %d\nnext : %ls\n", (unsigned long long)elem[0].data, (int *)elem[0].next);
	return (elem);
}

int main(void)
{
	void *data[1];
	int		i[1] = {12};
	
	data[0] = i;
	ft_create_elem(data);
	return (0);
}