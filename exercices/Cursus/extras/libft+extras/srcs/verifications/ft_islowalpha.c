/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:49 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 01:20:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @return
 * True if the argument is an alphabetic lowercase argument.
*/
int	ft_islowalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isalpha(97));
	return(0);
} */