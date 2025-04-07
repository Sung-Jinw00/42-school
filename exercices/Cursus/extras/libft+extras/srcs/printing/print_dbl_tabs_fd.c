/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dbl_tabs_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:51:34 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:00:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Print all the stings of a list of strings in the fd chosen. 
*/
void	print_dlb_tabs_fd(int fd, char **tab)
{
	int	i;

	if (!tab || !tab[0])
		return ;
	i = -1;
	while (tab[++i])
		write(fd, tab[i], ft_strlen(tab[i]));
}
