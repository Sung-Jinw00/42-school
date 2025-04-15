/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dbl_tabs_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:51:34 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Print all the stings of a list of strings in the fd chosen. 
*/
void	print_array_fd(int fd, char **tab)
{
	int	i;

	if (!tab || !tab[0])
		return ;
	i = -1;
	while (tab[++i])
	{
		write(fd, tab[i], ft_strlen(tab[i]));
		write(fd, " ", 1);
	}
	write(fd, "\n", 1);
}
