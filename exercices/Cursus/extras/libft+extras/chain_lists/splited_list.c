/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:01:40 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/15 18:02:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* turn a list into a splited string */

char	**splited_list(t_list *list)
{
	int i;
	char **tab_env;
	
	i = len_list(list);
	tab_env = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (list)
	{
		tab_env[i++] = ft_strdup(list->data);
		list = list->next;
	}
	tab_env[i] = NULL;
	return (tab_env);
}
