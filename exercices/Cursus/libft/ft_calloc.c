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

	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

/* #include <stdio.h>
#include <string.h>

int main(void)
{
	int size = 8539;
	int i = 0;
 	void * d1 = ft_calloc(10, 8);
 	void * d2 = calloc(10, 8);

	while (i < 8)
		((char *)d1)[i++] += 48;
	i = 0;
	while (i < 8)
		((char *)d2)[i++] += 48;
	printf("original : %s\ncopie    : %s\n", (char *)d2, (char *)d1);
	if (memcmp(d1, d2, size * 8))
 		printf("fail");
	free(d1);
	free(d2);
	return(0);
} */