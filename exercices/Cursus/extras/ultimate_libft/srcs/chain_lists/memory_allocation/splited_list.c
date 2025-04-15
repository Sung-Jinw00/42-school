/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:27:09 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Creates an array of strings that corresponds to the datas of the chain list.
 * 
 * @return
 * The new array of strings.
*/
char	**splited_list(t_list *list)
{
	int		i;
	char	**tab_env;

	if (!list)
		return (NULL);
	i = len_list(list);
	tab_env = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (list)
	{
		tab_env[i++] = ft_strdup((const char *)list->data);
		list = list->next;
	}
	tab_env[i] = NULL;
	return (tab_env);
}
