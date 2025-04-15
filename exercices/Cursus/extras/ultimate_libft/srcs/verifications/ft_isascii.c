/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:53 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 14:52:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @return
 * True if the argument is an restrained ascii argument.
*/
bool	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isascii(127));
	return(0);
} */