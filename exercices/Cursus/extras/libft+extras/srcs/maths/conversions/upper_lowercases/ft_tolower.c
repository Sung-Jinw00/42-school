/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:18 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/08 15:49:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/**
 * @brief
 * Transform a majuscule letter into a minuscule.
 * 
 * @returns
 * - The minuscule letter of a majuscule.*/
/**
 * - Else, it returns the character unchanged.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%c\n", (char)ft_tolower('z'));
	return (0);
} */
