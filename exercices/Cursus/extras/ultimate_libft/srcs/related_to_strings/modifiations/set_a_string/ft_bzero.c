/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:32 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Set a generic pointer to zero.
 * 
 * @returns
 * - The a generic pointer, set to zero.
*/
void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = -1;
	while (++i < (int)n)
		*(char *)(s + i) = 0;
}

/* #include <stdio.h>

int	main(void)
{
	void *tab;
	int i = 0;

	tab = malloc(sizeof(char) * 13);
	if (!tab)
		return (0);
	ft_bzero(tab, 5);
	while (i < 5)
		printf("%c\n", *(char *)(tab + i++) + 48);
	return (0);
} */