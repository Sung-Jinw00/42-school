/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:53:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 19:48:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Because searching for the lenght of the string is annoying.
 * 
 * @return
 * The number of bytes wrote.
*/
int	ft_write(int fd, char *s)
{
	if (!s)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}
