/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:20:15 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 16:20:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(char *)(s + i++) = 0;
		i++;
	}
}

/* int	main(void)
{
	void *tab;

	tab = malloc(sizeof(char) * 13);
	if (!tab)
		return(NULL);
	ft_bzero(tab, 5);
	return (0);
} */