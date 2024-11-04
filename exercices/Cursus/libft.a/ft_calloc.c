/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:39 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:39 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	int		i;

	i = 0;
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb);
	return (tab);
}

/* #include <stdio.h>

int main(void)
{
	void *tab;
	int i = 0;
	
	tab = ft_calloc(13, sizeof(int));
	while (i < 13)
		printf("%c\n", *(char *)(tab + i++) + 48);
	return(0);
} */