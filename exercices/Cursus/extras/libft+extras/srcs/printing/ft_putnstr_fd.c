/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:23 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:56:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Print n characters of a string into the fd chosen. 
*/
void	ft_putnstr_fd(int fd, char *s, size_t n)
{
	if (!s)
		return ;
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	return ((void)write(fd, s, n));
}

/* int main(void)
{
	char *s = "Hello World";

	ft_putstr_fd(s, 1);
	return (0);
}  */