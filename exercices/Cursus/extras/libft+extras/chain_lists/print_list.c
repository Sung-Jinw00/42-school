/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/12 16:55:16 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"
#include <stdio.h>

/* print a chain list */

void	print_list(t_list *L)
{
	if (!L)
		printf("(null)");
	while (L)
	{
		printf("%d ", *(int *)(L->data));
		L = L->next;
	}
	printf("\n");
}
