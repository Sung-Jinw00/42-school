/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splits_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:24:32 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:52:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Free an array of array of strings and set it to NULL.
 * 
 * @param cmd_s is an pointer on an array of an array of strings.
*/
void	ft_free_splits_array(char ****cmd_s)
{
	int	j;

	if (!(*cmd_s) || !(*cmd_s)[0])
		return ;
	j = 0;
	while ((*cmd_s)[j])
		free_dbl_tab(&(*cmd_s)[j++]);
	if ((*cmd_s))
		free(*cmd_s);
	*cmd_s = NULL;
}
