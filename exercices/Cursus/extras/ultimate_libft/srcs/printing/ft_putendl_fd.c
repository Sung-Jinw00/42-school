/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:13 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Print a string in the fd chosen, followed by a newline. 
*/
void	ft_putendl_fd(int fd, char *s)
{
	if (!s)
		return ;
	return (write(fd, s, ft_strlen(s)), (void)write(fd, "\n", 1));
}

/* int main(void)
{
	char *s = "Hello World";

	ft_putendl_fd(s, 1);
	return (0);
} */
