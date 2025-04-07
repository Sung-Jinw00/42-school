/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:23 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 17:54:28 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* write n characters of a string into the fd chosen
*/
void	ft_putnstr_fd(int fd, char *s, int n)
{
	if (!s)
		return (0);
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	return ((void)write(fd, s, ft_strlen(n)));
}

/* int main(void)
{
	char *s = "Hello World";

	ft_putstr_fd(s, 1);
	return (0);
}  */