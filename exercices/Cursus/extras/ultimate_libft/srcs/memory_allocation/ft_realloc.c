/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:39 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Reallocates the memory of ptr by size bytes. The content is unchanged.
 * 
 * @returns
 * - If "ptr" is NULL, then the call is equivalent to calloc(size).*/
/**
 * - If "size" is equal to  zero, and "ptr" is not NULL, then the call
 * is equivalent to free(ptr).*/
/**
 * - Else, it will returns NULL.
*/
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	i;

	if (size == 0 && ptr)
		return (free(ptr), NULL);
	new_ptr = (void *)ft_calloc(sizeof(void *), size);
	if (!new_ptr)
		return (NULL);
	i = -1;
	while ((char *)ptr && ++i < size)
		*(char *)(new_ptr + i) = *(char *)(ptr + i);
	if (ptr)
		free(ptr);
	return (new_ptr);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	void *ptr = strdup("Hello World");
	void *cpy = ft_upgrade_realloc(ptr, 5);

	printf("result : %s\n", (char *)cpy);
	free(cpy);
	return(0);
} */