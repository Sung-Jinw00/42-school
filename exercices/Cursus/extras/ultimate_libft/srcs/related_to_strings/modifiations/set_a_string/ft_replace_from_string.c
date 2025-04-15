/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_from_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:46:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Replace every string equals to "to_search" inside of str by "to_replace".
 * 
 * @param str The string that will be changed.
 * @param to_search The string to search in str.
 * @param to_replace The string to that will replace "to_search" in str.
 * @param to_free If to_free = true, str will be freed.
 * 
 * @return
 * - If str doesn't contains "to_search" string, the function behave like
 * strdup(str).*/
/**
 * -Else if the function fails or if str is NULL, the function will returns
 * NULL.*/
/**
* - The new allocated string modified.
 */
char	*ft_replace_from_string(char *str, char *to_search, char *to_replace,
int to_free)
{
	char	*new_str;
	char	*tmp;
	size_t	i;

	i = 0;
	new_str = NULL;
	tmp = NULL;
	while (str && i < ft_strlen(str) && str[i])
	{
		if (!ft_strncmp(str + i, to_search, ft_strlen(to_search)))
		{
			new_str = ft_strjoin_n_free(new_str, to_replace, 1);
			i += ft_strlen(to_search);
		}
		else
		{
			tmp = ft_strndup(str + i, ft_str_strlen(str + i, to_search));
			i += ft_strlen(tmp);
			new_str = ft_strjoin_n_free(new_str, tmp, 12);
		}
	}
	if (to_free)
		free(str);
	return (new_str);
}
