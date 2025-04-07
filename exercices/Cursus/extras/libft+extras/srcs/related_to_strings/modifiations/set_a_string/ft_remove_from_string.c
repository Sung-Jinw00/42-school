/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_from_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:46:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 19:41:15 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Remove every characters of to_delete string to str and return the new line,
 * can free str.
 * 
 * @param str The string that will be changed.
 * @param to_delete The string that contains the characters that will be
 * removed from str.
 * @param to_free If to_free = true, str will be freed.
 * 
 * @return
 * The new allocated string without the characters of to_delete. If the
 * function fails or if str is NULL, the function will returns NULL.
*/
char	*ft_remove_from_string(char *str, char *to_delete, int to_free)
{
	char	**tab;
	char	*line;
	char	*tmp;
	int		i;

	tab = ft_split(str, to_delete);
	if (!tab)
		return (NULL);
	i = 0;
	line = ft_strdup(tab[i++]);
	tmp = NULL;
	while (tab[i])
	{
		tmp = ft_strjoin(line, tab[i++]);
		if (!tmp)
			return (free_dbl_tab(tab), free(line), NULL);
		free(line);
		line = tmp;
	}
	free_dbl_tab(tab);
	if (to_free)
		free(str);
	return (line);
}
