/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:23 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:55:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Print a string into the fd chosen. 
*/
void	ft_putstr_fd(int fd, char *s)
{
	if (!s)
		return ;
	return ((void)write(fd, s, ft_strlen(s)));
}

/* int main(void)
{
	char *s = "Hello World";

	ft_putstr_fd(s, 1);
	return (0);
}  */