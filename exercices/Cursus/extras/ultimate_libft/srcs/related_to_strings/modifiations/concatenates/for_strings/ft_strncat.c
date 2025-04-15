/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:09:37 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Copy n bytes of src at the end of dest.
 * 
 * @param dest The string that will be modified.
 * @param src The string that will be added.
 * @param nb The number of bytes of src that will be copied in dest.
 * 
 * @return
 * - If dest is NULL : The function returns NULL. */
/**
 * - Else if src is NULL : The function returns dest unchanged.*/
/**
 * - Else : The function returns the new dest.
*/
char	*ft_strncat(char *dest, char *src, size_t nb)
{
	int		i;
	size_t	j;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/*int main(void)
{
	char dest[] = "Hello ";
	char src[] = "World";
	unsigned int nb = 7;

	printf("%s\n", ft_strncat(dest, src, nb));
	return (0);
}*/