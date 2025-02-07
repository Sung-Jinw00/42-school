/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_from_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:46:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/07 14:47:13 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* remove every characters of to_delete string to str and return the new line */

char	*ft_remove_from_string(char *str, char *to_delete)
{
	char	**tab;
	char	*line;
	char	*tmp;
	int		i;

	tab = ft_split(str, to_delete);
	if (!tab)
			return(NULL);
	i = 0;
	line = ft_strdup(tab[i++]);
	tmp = NULL;
	while (tab[i])
	{
		tmp = ft_strjoin(line, tab[i++]);
		if (!tmp)
			return(ft_free_bouble_tabs(tab), free(line), NULL);
		free(line);
		line = tmp;
	}
	return (line);
}
