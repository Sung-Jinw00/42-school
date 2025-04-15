/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:53:35 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Write an infinite amount of strings in the fd chosen.
 * 
 * Because calling fprintf to write multiple strings in the fd chosen is
 * annoying (and forbidden).
 * 
 * Write as long as a string is non NULL.
 * 
 * @note
 * The last argument should be NULL, otherwise, the function may have an
 * undefined behavior.
 * 
 * @return
 * The number of bytes wrote.
*/
int	ft_multi_write(int fd, char *s1, ...)
{
	char	*strn;
	va_list	args;
	int		char_print;

	char_print = 0;
	if (!s1)
		return (char_print);
	char_print += write(fd, s1, ft_strlen(s1));
	va_start(args, s1);
	strn = va_arg(args, char *);
	while (strn)
	{
		char_print += write(fd, strn, ft_strlen(strn));
		strn = va_arg(args, char *);
	}
	va_end(args);
	return (char_print);
}
