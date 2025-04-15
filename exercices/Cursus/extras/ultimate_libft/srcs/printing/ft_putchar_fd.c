/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:47:12 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 00:02:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Print a char in the fd chosen. 
*/
void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

/* int main(void)
{
	char *s = "H";

	ft_putchar_fd(s, 1);
	return (0);
}  */