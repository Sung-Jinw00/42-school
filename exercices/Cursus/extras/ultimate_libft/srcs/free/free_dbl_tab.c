/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bouble_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:39:14 by marvin            #+#    #+#             */
/*   Updated: 2025/01/19 15:39:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Free an array of strings and set it to NULL.
 * 
 * @param str is an pointer on an array of strings.
*/
void	free_array(char ***str)
{
	int	j;

	if (!*str || !(*str)[0])
		return ;
	j = 0;
	while ((*str)[j])
		ft_free(&(*str)[j++]);
	if (*str)
		free(*str);
	*str = NULL;
}
