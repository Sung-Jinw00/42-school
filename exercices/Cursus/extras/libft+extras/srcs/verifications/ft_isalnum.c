/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:44 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 01:20:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @return
 * True if the argument is an alphanumeric argument.
*/
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_isalnum(99));
	return(0);
} */