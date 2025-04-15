/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:01:08 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 17:01:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Print the whole chain list datas.
 * 
 * @param L If L = NULL, the function will print "(null)".
 * @param data_type :*/
/**
 * - If data_type = "string", the function will print a string.*/
/**
 * - Else if data_type = "int", the function will print an int.*/
/**
 * - Else if data_type = "string array", the function will print an array of
 * strings.*/
/**
 * - Else the function won't print any data.
*/
void	print_list(t_list *L, char *data_type)
{
	int	i;

	if (!L)
		printf("(null)\n");
	i = 0;
	while (L
		&& !str_multi_cmp(data_type, "string", "int", "string array", NULL))
	{
		printf("Cell %d : ", i);
		if (!ft_strcmp(data_type, "string"))
			printf("%s\n", (char *)L->data);
		else if (!ft_strcmp(data_type, "int"))
			printf("%d\n", *(int *)L->data);
		if (!ft_strcmp(data_type, "string array"))
			print_array((char **)L->data);
		L = L->next;
		i++;
	}
}
