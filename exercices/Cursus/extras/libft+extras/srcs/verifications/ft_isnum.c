/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:52:11 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/14 14:52:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @return
 * True if the argument is an number.
*/
bool	ft_isnum(int c)
{
	return (c >= '0' && c <= '9');
}

/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isnum(47));
	return(0);
} */