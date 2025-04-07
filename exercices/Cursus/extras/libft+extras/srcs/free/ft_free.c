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

#include "libft_extras.h"

/**
 * @brief
 * Free a string and set it to NULL.
 * 
 * @param str is an pointer on an string.
*/
void	ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}
